def Make_colour_index(Meaning, minimum, maximum):

    Red_index_colour = int((Meaning - minimum)/(maximum - minimum) * (255 - 60)) + 60
    index = hex(Red_index_colour)
    index = index.lstrip('0x')
    results = '#' + index  + '0000'


    return results


