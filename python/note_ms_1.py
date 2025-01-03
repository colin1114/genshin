import cv2

# 读取二维码图片
image = cv2.imread('sb.png')

# 创建二维码解码器
detector = cv2.QRCodeDetector()

# 解码
value, pts, qr_code = detector(image)

# 输出解码结果
if value:
    print("Decoded value:", value)
else:
    print("QRCode not detected.")
