#!/usr/bin/python3
''' method DPS determines if all box can be opened'''


def canUnlockAll(boxes) :
    if not boxes or boxes[0] is None:
        return False
    
    lenght_boxes = len(boxes)
    keys = boxes[0][:]
    open_box = {0}

    def check_box(index):
        if index not in open_box:
            open_box.add(index)
            keys.extend(boxes[index])
        

    while keys:
        box = keys.pop()
        if 0 <= box < lenght_boxes:
            check_box(box)



    return len(open_box) == lenght_boxes
