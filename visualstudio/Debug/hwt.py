import sys

cells = [0]
ptr = 0

ptr += 1
if ptr == len(cells): cells.append(0)
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
while cells[ptr]:
	pass
	cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
	ptr = len(cells) - 1 if ptr == 0 else ptr - 1
	cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
	cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
	cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
	cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
	cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
	cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
	cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
	cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
	cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
	ptr += 1
	if ptr == len(cells): cells.append(0)
ptr = len(cells) - 1 if ptr == 0 else ptr - 1
sys.stdout.write(chr(cells[ptr]))
ptr += 1
if ptr == len(cells): cells.append(0)
while cells[ptr]:
	pass
while cells[ptr]:
	pass
	ptr = len(cells) - 1 if ptr == 0 else ptr - 1
	cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
ptr += 1
if ptr == len(cells): cells.append(0)
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
ptr += 1
if ptr == len(cells): cells.append(0)
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
while cells[ptr]:
	pass
	cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
ptr += 1
if ptr == len(cells): cells.append(0)
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
ptr += 1
if ptr == len(cells): cells.append(0)
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
while cells[ptr]:
	pass
	ptr += 1
	if ptr == len(cells): cells.append(0)
	while cells[ptr]:
		pass
		cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
		ptr += 1
		if ptr == len(cells): cells.append(0)
		cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
		cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
		cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
		ptr = len(cells) - 1 if ptr == 0 else ptr - 1
		ptr = len(cells) - 1 if ptr == 0 else ptr - 1
		cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
		cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
		cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
		ptr += 1
		if ptr == len(cells): cells.append(0)
	ptr = len(cells) - 1 if ptr == 0 else ptr - 1
	ptr = len(cells) - 1 if ptr == 0 else ptr - 1
ptr += 1
if ptr == len(cells): cells.append(0)
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
sys.stdout.write(chr(cells[ptr]))
ptr += 1
if ptr == len(cells): cells.append(0)
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
ptr += 1
if ptr == len(cells): cells.append(0)
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
sys.stdout.write(chr(cells[ptr]))
sys.stdout.write(chr(cells[ptr]))
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
sys.stdout.write(chr(cells[ptr]))
ptr += 1
if ptr == len(cells): cells.append(0)
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
sys.stdout.write(chr(cells[ptr]))
ptr = len(cells) - 1 if ptr == 0 else ptr - 1
ptr = len(cells) - 1 if ptr == 0 else ptr - 1
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
while cells[ptr]:
	pass
	ptr += 1
	if ptr == len(cells): cells.append(0)
	while cells[ptr]:
		pass
		cells[ptr] = ord(sys.stdin.read(1))
		ptr += 1
		if ptr == len(cells): cells.append(0)
		cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
	ptr += 1
	if ptr == len(cells): cells.append(0)
	ptr += 1
	if ptr == len(cells): cells.append(0)
ptr = len(cells) - 1 if ptr == 0 else ptr - 1
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
sys.stdout.write(chr(cells[ptr]))
ptr += 1
if ptr == len(cells): cells.append(0)
ptr += 1
if ptr == len(cells): cells.append(0)
sys.stdout.write(chr(cells[ptr]))
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
sys.stdout.write(chr(cells[ptr]))
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
sys.stdout.write(chr(cells[ptr]))
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
cells[ptr] = cells[ptr] - 1 if cells[ptr] > 0 else 255
sys.stdout.write(chr(cells[ptr]))
ptr += 1
if ptr == len(cells): cells.append(0)
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
sys.stdout.write(chr(cells[ptr]))
ptr += 1
if ptr == len(cells): cells.append(0)
cells[ptr] = cells[ptr] + 1 if cells[ptr] < 255 else 0
sys.stdout.write(chr(cells[ptr]))
