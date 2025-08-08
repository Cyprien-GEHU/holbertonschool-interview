#!/usr/bin/python3
def canUnlockAll(boxes) :
    if not boxes:
        return False
    elif boxes[0] is None:
        return False
    
    lenght_boxes = len(boxes)
    first_box = boxes[0]
    open_box = {0}

    def check_box(index):
        if index in open_box:
            return
        open_box.add(index)
        for key in boxes[index]:
            if 0 <= key < lenght_boxes:
                check_box(key)

    while first_box:
        box = first_box.pop()
        check_box(box)



    return len(open_box) == lenght_boxes