#!/usr/bin/env python
"""Parse RawData from KeyboardLayoutGenerator and generate RGB position matrix."""

import argparse
import sys
import json
import re
import pprint

def safe_str(obj):
    """ return the byte string representation of obj """
    try:
        return str(obj)
    except UnicodeEncodeError:
        # obj is unicode
        return unicode(obj).encode('unicode_escape')
class Key:
    """Define key class."""
    ORIGIN_CENTER = 1
    ORIGIN_TOP_LEFT = 2
    ORIGIN_BOTTOM_RIGHT = 3

    def __init__(self, label, x=0.0, y=0.0, w=1.0, h=1.0, origin=None):
        """Init key."""
        self.x = x
        self.y = y
        self.w = w
        self.h = h
        self.label = re.sub(r"(.+)\n.*", r"\1", safe_str(label))
        self.origin = origin if origin else self.ORIGIN_CENTER

    @property
    def origin_x(self):
        """Calculate X origin ."""
        if self.origin == self.ORIGIN_CENTER:
            value = self.x + (self.w / 2.0)
        elif self.origin == self.ORIGIN_TOP_LEFT:
            value = self.x
        elif self.origin == self.ORIGIN_BOTTOM_RIGHT:
            value = self.x + self.w

        return value

    @property
    def origin_y(self):
        """Calculate Y origin ."""
        if self.origin == self.ORIGIN_CENTER:
            value = self.y + (self.h / 2.0)
        elif self.origin == self.ORIGIN_TOP_LEFT:
            value = self.y
        elif self.origin == self.ORIGIN_BOTTOM_RIGHT:
            value = self.y + self.h

        return value

    def __str__(self):
        """.Dump out string"""
        return u"{0.x}, {0.y}   {0.w}, {0.h}".format(self)

    def get_matrix_position(self, width, height):
        """Calculate x/y."""
        return [self.origin_x * width, self.origin_y * height]

def get_key(row, x=0.0, y=0.0, origin=Key.ORIGIN_CENTER):
    """Column iterator for kle data."""
    w = 1.0
    h = 1.0

    for i in row:
        if isinstance(i, unicode):
            k = Key(i, x, y, w, h, origin)
            x += w
            w = 1.0
            h = 1.0
            yield k
        elif isinstance(i, dict):
            if "w" in i:
                w = i["w"]
            if "h" in i:
                h = i["h"]
            if "y" in i:
                y += i["y"]
            if "x" in i:
                x += i["x"]


class Keyboard:
    """Define keyboard."""
    def __init__(self, data, origin=Key.ORIGIN_CENTER):
        """Init keyboard."""
        self.rows = []
        self.width = 0.0
        self.height = 0.0
        self.origin = origin
        self.columns = 0

        y = 0.0
        for row in data:
            x = 0.0
            key_row=[]
            c = 0
            for key in get_key(row, x=x, y=y, origin=self.origin):
                c += 1
                if (key.x + key.w) > self.width:
                    self.width = key.x + key.w

                if (key.y + key.h) > self.height:
                    self.height = key.y + key.h

                if key.y > y:
                    y = key.y

                key_row.append(key)
            if c > self.columns:
                self.columns = c
            self.rows.append(key_row)
            y += 1.0


    def __len__(self):
        """Count keys."""
        return sum([len(x) for x in self.rows])

    def get_matrix_positions(self, width, height):
        """Generate list of lists."""
        cellx = float(width) / (self.width - 1.0)
        celly = float(height) / (self.height - 1.0)
        rows = []
        for r in self.rows:
            row = []
            for c in r:
                x, y = c.get_matrix_position(cellx, celly)
                if self.origin == Key.ORIGIN_CENTER:
                    row.append([int((x-(cellx/2))+0.5), int((y-(celly/2))+0.5)])
                elif self.origin == Key.ORIGIN_TOP_LEFT:
                    row.append([int(x+0.5), int(y+0.5)])
                elif self.origin == Key.ORIGIN_BOTTOM_RIGHT:
                    row.append([int((x-cellx)+0.5), int((y-celly)+0.5)])
            rows.append(row)

        return rows

    def get_json_details(self):
        """Generate info.json details."""
        result = []
        for row in self.rows:
            for col in row:
                cell = {
                    "label": col.label,
                    "x": col.x,
                    "y": col.y,
                }

                if col.w != 1.0:
                    cell.update({"w": col.w})
                if col.h != 1.0:
                    cell.update({"h": col.h})

                result.append(cell)

        return result


def as_cpp(pos):
    """Format as cpp header."""
    return "{{ {0:3}, {1:3} }},".format(*pos)

def main():# pylint: disable=R0914,R0915,R1260
    """Do main function."""
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.ArgumentDefaultsHelpFormatter
    )

    parser.add_argument(
        "path",
        type=str,
        nargs="*",
        default=[],
        help="Path to rawdata, read stdin otherwise."
    )

    parser.add_argument(
        "--width",
        type=int,
        default=224,
        action="store",
        help="Structure max X."
    )

    parser.add_argument(
        "--height",
        type=int,
        default=64,
        action="store",
        help="Structure max Y."
    )

    parser.add_argument(
        "--origin",
        choices=[
            "CENTER",
            "TOP_LEFT",
            "BOTTOM_RIGHT",
        ],
        help="Origin of key, for positioning",
        default="CENTER"
    )

    parser.add_argument(
        "--mode",
        choices=[
            "RGBMATRIX",
            "INFOJSON",
        ],
        help="Output mode.",
        default="RGBMATRIX"
    )

    parser.add_argument(
        "-d", "--debug",
        default=False,
        action="store_true",
        help="Debug mode."
    )

    args = parser.parse_args()

    data = ""

    if args.path:
        with open(args.path[0], "r") as o:
            data = o.read()
    else:
        # try stdin
        while True:
            try:
                line = sys.stdin.readline()
            except KeyboardInterrupt:
                break

            if not line:
                break

            line = line.strip()

            if line:
                data += line

    # massage into JSON.. WHY doesn't KLE use JSON!
    data = re.sub("([a-z0-9]+):", "\"\\1\":", data)

    data = json.loads("[" + data + "]")
    if args.debug:
        for d in data:
            print d

    if args.mode == "RGBMATRIX":
        if args.origin == "CENTER":
            origin = Key.ORIGIN_CENTER
        elif args.origin == "TOP_LEFT":
            origin = Key.ORIGIN_TOP_LEFT
        elif args.origin == "BOTTOM_RIGHT":
            origin = Key.ORIGIN_BOTTOM_RIGHT
    else:
        origin = Key.ORIGIN_TOP_LEFT

    kb = Keyboard(data, origin)

    if args.mode == "RGBMATRIX":
        print "Keyboard dimension:", kb.width, "x", kb.height
        print "Keyboard key count:", len(kb)
        print
        row_i = 0
        print "        ",
        for c in range(kb.columns):
            print "/* {0:^7} */".format(c),
        print
        for r in kb.get_matrix_positions(args.width, args.height):
            print "/* {0:2} */".format(row_i),
            for c in r:
                print as_cpp(c),
            print
            row_i += 1
    elif args.mode == "INFOJSON":
        pp = pprint.PrettyPrinter(indent=4)
        info = {
            "keyboard_name": "",
            "url": "",
            "maintainer": "",
            "keyboard_folder": "",
            "width": kb.width,
            "height": kb.height,
            "layouts": {"LAYOUT":{"layout":[], "key_count":0}},
        }
        info["layouts"]["LAYOUT"]["key_count"] = len(kb) 
        info["layouts"]["LAYOUT"]["layout"] = kb.get_json_details()
        pp.pprint(info)

    # "LAYOUT_numpad_6x4": {
    #   "key_count": 21,
    #   "layout": [
    #     {"label":"Esc", "x":0, "y":0},
    #     {"label":"Tab", "x":1, "y":0},
    #     {"label":"Fn", "x":2, "y":0},
    #     {"label":"Back", "x":3, "y":0},
    #     {"label":"Num Lock", "x":0, "y":1},
    #     {"label":"/", "x":1, "y":1},
    #     {"label":"*", "x":2, "y":1},
    #     {"label":"-", "x":3, "y":1},
    #     {"label":"7", "x":0, "y":2},
    #     {"label":"8", "x":1, "y":2},
    #     {"label":"9", "x":2, "y":2},
    #     {"label":"4", "x":0, "y":3},
    #     {"label":"5", "x":1, "y":3},
    #     {"label":"6", "x":2, "y":3},
    #     {"label":"+", "x":3, "y":2, "h":2},
    #     {"label":"1", "x":0, "y":4},
    #     {"label":"2", "x":1, "y":4},
    #     {"label":"3", "x":2, "y":4},
    #     {"label":"0", "x":0, "y":5, "w":2},
    #     {"label":".", "x":2, "y":5},
    #     {"label":"Enter", "x":3, "y":4, "h":2}
    #   ]
    # },


# {
#   "keyboard_name": "LFK87/SMK87",
#   "url": "",
#   "maintainer": "qmk",
#   "width": 18.25,
#   "height": 6.5,
#   "layouts": {
#     "LAYOUT_tkl_ansi": {
#       "layout": [{"label":"Esc", "x":0, "y":0}, {"label":"F1", "x":2, "y":0}, {"label":"F2", "x":3, "y":0}, {"label":"F3", "x":4, "y":0}, {"label":"F4", "x":5, "y":0}, {"label":"F5", "x":6.5, "y":0}, {"label":"F6", "x":7.5, "y":0}, {"label":"F7", "x":8.5, "y":0}, {"label":"F8", "x":9.5, "y":0}, {"label":"F9", "x":11, "y":0}, {"label":"F10", "x":12, "y":0}, {"label":"F11", "x":13, "y":0}, {"label":"F12", "x":14, "y":0}, {"label":"PrtSc", "x":15.25, "y":0}, {"label":"Scroll Lock", "x":16.25, "y":0}, {"label":"Pause", "x":17.25, "y":0}, {"label":"~", "x":0, "y":1.5}, {"label":"!", "x":1, "y":1.5}, {"label":"@", "x":2, "y":1.5}, {"label":"#", "x":3, "y":1.5}, {"label":"$", "x":4, "y":1.5}, {"label":"%", "x":5, "y":1.5}, {"label":"^", "x":6, "y":1.5}, {"label":"&", "x":7, "y":1.5}, {"label":"*", "x":8, "y":1.5}, {"label":"(", "x":9, "y":1.5}, {"label":")", "x":10, "y":1.5}, {"label":"_", "x":11, "y":1.5}, {"label":"+", "x":12, "y":1.5}, {"label":"Backspace", "x":13, "y":1.5, "w":2}, {"label":"Insert", "x":15.25, "y":1.5}, {"label":"Home", "x":16.25, "y":1.5}, {"label":"PgUp", "x":17.25, "y":1.5}, {"label":"Tab", "x":0, "y":2.5, "w":1.5}, {"label":"Q", "x":1.5, "y":2.5}, {"label":"W", "x":2.5, "y":2.5}, {"label":"E", "x":3.5, "y":2.5}, {"label":"R", "x":4.5, "y":2.5}, {"label":"T", "x":5.5, "y":2.5}, {"label":"Y", "x":6.5, "y":2.5}, {"label":"U", "x":7.5, "y":2.5}, {"label":"I", "x":8.5, "y":2.5}, {"label":"O", "x":9.5, "y":2.5}, {"label":"P", "x":10.5, "y":2.5}, {"label":"{", "x":11.5, "y":2.5}, {"label":"}", "x":12.5, "y":2.5}, {"label":"|", "x":13.5, "y":2.5, "w":1.5}, {"label":"Delete", "x":15.25, "y":2.5}, {"label":"End", "x":16.25, "y":2.5}, {"label":"PgDn", "x":17.25, "y":2.5}, {"label":"Caps Lock", "x":0, "y":3.5, "w":1.75}, {"label":"A", "x":1.75, "y":3.5}, {"label":"S", "x":2.75, "y":3.5}, {"label":"D", "x":3.75, "y":3.5}, {"label":"F", "x":4.75, "y":3.5}, {"label":"G", "x":5.75, "y":3.5}, {"label":"H", "x":6.75, "y":3.5}, {"label":"J", "x":7.75, "y":3.5}, {"label":"K", "x":8.75, "y":3.5}, {"label":"L", "x":9.75, "y":3.5}, {"label":":", "x":10.75, "y":3.5}, {"label":"\"", "x":11.75, "y":3.5}, {"label":"Enter", "x":12.75, "y":3.5, "w":2.25}, {"label":"Shift", "x":0, "y":4.5, "w":2.25}, {"label":"Z", "x":2.25, "y":4.5}, {"label":"X", "x":3.25, "y":4.5}, {"label":"C", "x":4.25, "y":4.5}, {"label":"V", "x":5.25, "y":4.5}, {"label":"B", "x":6.25, "y":4.5}, {"label":"N", "x":7.25, "y":4.5}, {"label":"M", "x":8.25, "y":4.5}, {"label":"<", "x":9.25, "y":4.5}, {"label":">", "x":10.25, "y":4.5}, {"label":"?", "x":11.25, "y":4.5}, {"label":"Shift", "x":12.25, "y":4.5, "w":2.75}, {"label":"\u2191", "x":16.25, "y":4.5}, {"label":"Ctrl", "x":0, "y":5.5, "w":1.25}, {"label":"Win", "x":1.25, "y":5.5, "w":1.25}, {"label":"Alt", "x":2.5, "y":5.5, "w":1.25}, {"x":3.75, "y":5.5, "w":6.25}, {"label":"Alt", "x":10, "y":5.5, "w":1.25}, {"label":"Win", "x":11.25, "y":5.5, "w":1.25}, {"label":"Menu", "x":12.5, "y":5.5, "w":1.25}, {"label":"Ctrl", "x":13.75, "y":5.5, "w":1.25}, {"label":"\u2190", "x":15.25, "y":5.5}, {"label":"\u2193", "x":16.25, "y":5.5}, {"label":"\u2192", "x":17.25, "y":5.5}]
#     },
#     "LAYOUT_tkl_iso": {
#       "layout": [{"label":"Esc", "x":0, "y":0}, {"label":"F1", "x":2, "y":0}, {"label":"F2", "x":3, "y":0}, {"label":"F3", "x":4, "y":0}, {"label":"F4", "x":5, "y":0}, {"label":"F5", "x":6.5, "y":0}, {"label":"F6", "x":7.5, "y":0}, {"label":"F7", "x":8.5, "y":0}, {"label":"F8", "x":9.5, "y":0}, {"label":"F9", "x":11, "y":0}, {"label":"F10", "x":12, "y":0}, {"label":"F11", "x":13, "y":0}, {"label":"F12", "x":14, "y":0}, {"label":"PrtSc", "x":15.25, "y":0}, {"label":"Scroll Lock", "x":16.25, "y":0}, {"label":"Pause", "x":17.25, "y":0}, {"label":"\u00ac", "x":0, "y":1.5}, {"label":"!", "x":1, "y":1.5}, {"label":"\"", "x":2, "y":1.5}, {"label":"\u00a3", "x":3, "y":1.5}, {"label":"$", "x":4, "y":1.5}, {"label":"%", "x":5, "y":1.5}, {"label":"^", "x":6, "y":1.5}, {"label":"&", "x":7, "y":1.5}, {"label":"*", "x":8, "y":1.5}, {"label":"(", "x":9, "y":1.5}, {"label":")", "x":10, "y":1.5}, {"label":"_", "x":11, "y":1.5}, {"label":"+", "x":12, "y":1.5}, {"label":"Backspace", "x":13, "y":1.5, "w":2}, {"label":"Insert", "x":15.25, "y":1.5}, {"label":"Home", "x":16.25, "y":1.5}, {"label":"PgUp", "x":17.25, "y":1.5}, {"label":"Tab", "x":0, "y":2.5, "w":1.5}, {"label":"Q", "x":1.5, "y":2.5}, {"label":"W", "x":2.5, "y":2.5}, {"label":"E", "x":3.5, "y":2.5}, {"label":"R", "x":4.5, "y":2.5}, {"label":"T", "x":5.5, "y":2.5}, {"label":"Y", "x":6.5, "y":2.5}, {"label":"U", "x":7.5, "y":2.5}, {"label":"I", "x":8.5, "y":2.5}, {"label":"O", "x":9.5, "y":2.5}, {"label":"P", "x":10.5, "y":2.5}, {"label":"{", "x":11.5, "y":2.5}, {"label":"}", "x":12.5, "y":2.5}, {"label":"Delete", "x":15.25, "y":2.5}, {"label":"End", "x":16.25, "y":2.5}, {"label":"PgDn", "x":17.25, "y":2.5}, {"label":"Caps Lock", "x":0, "y":3.5, "w":1.75}, {"label":"A", "x":1.75, "y":3.5}, {"label":"S", "x":2.75, "y":3.5}, {"label":"D", "x":3.75, "y":3.5}, {"label":"F", "x":4.75, "y":3.5}, {"label":"G", "x":5.75, "y":3.5}, {"label":"H", "x":6.75, "y":3.5}, {"label":"J", "x":7.75, "y":3.5}, {"label":"K", "x":8.75, "y":3.5}, {"label":"L", "x":9.75, "y":3.5}, {"label":":", "x":10.75, "y":3.5}, {"label":"@", "x":11.75, "y":3.5}, {"label":"~", "x":12.75, "y":3.5}, {"label":"Enter", "x":13.75, "y":2.5, "w":1.25, "h":2}, {"label":"Shift", "x":0, "y":4.5, "w":1.25}, {"label":"|", "x":1.25, "y":4.5}, {"label":"Z", "x":2.25, "y":4.5}, {"label":"X", "x":3.25, "y":4.5}, {"label":"C", "x":4.25, "y":4.5}, {"label":"V", "x":5.25, "y":4.5}, {"label":"B", "x":6.25, "y":4.5}, {"label":"N", "x":7.25, "y":4.5}, {"label":"M", "x":8.25, "y":4.5}, {"label":"<", "x":9.25, "y":4.5}, {"label":">", "x":10.25, "y":4.5}, {"label":"?", "x":11.25, "y":4.5}, {"label":"Shift", "x":12.25, "y":4.5, "w":2.75}, {"label":"\u2191", "x":16.25, "y":4.5}, {"label":"Ctrl", "x":0, "y":5.5, "w":1.25}, {"label":"Win", "x":1.25, "y":5.5, "w":1.25}, {"label":"Alt", "x":2.5, "y":5.5, "w":1.25}, {"x":3.75, "y":5.5, "w":6.25}, {"label":"AltGr", "x":10, "y":5.5, "w":1.25}, {"label":"Win", "x":11.25, "y":5.5, "w":1.25}, {"label":"Menu", "x":12.5, "y":5.5, "w":1.25}, {"label":"Ctrl", "x":13.75, "y":5.5, "w":1.25}, {"label":"\u2190", "x":15.25, "y":5.5}, {"label":"\u2193", "x":16.25, "y":5.5}, {"label":"\u2192", "x":17.25, "y":5.5}]
#     }
#   }
# }

    return 0

if __name__ == "__main__":
    sys.exit(main())
