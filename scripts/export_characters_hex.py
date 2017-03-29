import sys
from PIL import Image

if len(sys.argv) >= 2:
	filename = sys.argv[1]
else:
	filename = "../assets/characters.png"
im = Image.open(filename)
print im.format, im.size, im.mode
for row in range(16):
	for column in range(16):
		for charY in range(8):
			y = row*8+charY
			val = 0
			for charX in range(4):
				pixel = im.getpixel((column*8+charX, y))[0] / 64
				val |= (pixel << (3-charX)*2)
			hexStr = "%0.2X" % val
			print hexStr,
			val = 0
			for charX in range(4,8):
				pixel = im.getpixel((column*8+charX, y))[0] / 64
				val |= (pixel << (7-charX)*2)
			hexStr = "%0.2X" % val
			print hexStr,
		print ""
