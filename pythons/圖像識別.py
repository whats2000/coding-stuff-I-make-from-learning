import numpy as np
from PIL import Image, ImageDraw
import easyocr
import cv2

reader = easyocr.Reader(['ch_tra'], gpu=True, model_storage_directory='./model')


def detect_png(color_detect=False):
    pre_img = cv2.cvtColor(cv2.imread(r'box.png'), cv2.COLOR_BGR2HSV)

    if color_detect:
        low_hsv = np.array([0, 43, 46])
        high_hsv = np.array([10, 255, 255])

        pre2_img = cv2.inRange(pre_img, lowerb=low_hsv, upperb=high_hsv)
    else:
        pre2_img = pre_img

    cv2.imwrite('box_conv.png', pre2_img)

    detect_text = reader.readtext(r'box_conv.png')

    img = Image.open(r'box_conv.png')
    draw = ImageDraw.Draw(img)

    for t in detect_text:
        draw.rectangle((tuple(t[0][0]), tuple(t[0][2])), fill=None, outline='red', width=2)

    img.save("box_detect.png")

    print('偵測字串: ', detect_text)


detect_png(True)
