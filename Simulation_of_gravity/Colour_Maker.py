import math


def Make_colour_index(Meaning, minimum, maximum):
    Red_index_colour = 60 + int((580 * math.atan((Meaning - minimum) / (maximum - minimum))) / math.pi)
    index = hex(Red_index_colour)
    index = index.lstrip('0x')
    results = '#' + index + '0000'

    return results