@cells = [0]
@ptr = 0

@ptr += 1
@cells.push(0) if @ptr == @cells.length
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
while @cells[@ptr] != 0
	@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
	@ptr = (@ptr == 0 ? @cells.size - 1 : @ptr - 1)
	@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
	@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
	@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
	@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
	@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
	@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
	@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
	@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
	@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
	@ptr += 1
	@cells.push(0) if @ptr == @cells.length
end
@ptr = (@ptr == 0 ? @cells.size - 1 : @ptr - 1)
print @cells[@ptr].chr if @cells[@ptr]
@ptr += 1
@cells.push(0) if @ptr == @cells.length
while @cells[@ptr] != 0
end
while @cells[@ptr] != 0
	@ptr = (@ptr == 0 ? @cells.size - 1 : @ptr - 1)
	@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
end
@ptr += 1
@cells.push(0) if @ptr == @cells.length
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@ptr += 1
@cells.push(0) if @ptr == @cells.length
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
while @cells[@ptr] != 0
	@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
end
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@ptr += 1
@cells.push(0) if @ptr == @cells.length
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@ptr += 1
@cells.push(0) if @ptr == @cells.length
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
while @cells[@ptr] != 0
	@ptr += 1
	@cells.push(0) if @ptr == @cells.length
	while @cells[@ptr] != 0
		@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
		@ptr += 1
		@cells.push(0) if @ptr == @cells.length
		@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
		@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
		@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
		@ptr = (@ptr == 0 ? @cells.size - 1 : @ptr - 1)
		@ptr = (@ptr == 0 ? @cells.size - 1 : @ptr - 1)
		@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
		@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
		@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
		@ptr += 1
		@cells.push(0) if @ptr == @cells.length
end
@ptr = (@ptr == 0 ? @cells.size - 1 : @ptr - 1)
@ptr = (@ptr == 0 ? @cells.size - 1 : @ptr - 1)
end
@ptr += 1
@cells.push(0) if @ptr == @cells.length
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
print @cells[@ptr].chr if @cells[@ptr]
@ptr += 1
@cells.push(0) if @ptr == @cells.length
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@ptr += 1
@cells.push(0) if @ptr == @cells.length
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
print @cells[@ptr].chr if @cells[@ptr]
print @cells[@ptr].chr if @cells[@ptr]
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
print @cells[@ptr].chr if @cells[@ptr]
@ptr += 1
@cells.push(0) if @ptr == @cells.length
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
print @cells[@ptr].chr if @cells[@ptr]
@ptr = (@ptr == 0 ? @cells.size - 1 : @ptr - 1)
@ptr = (@ptr == 0 ? @cells.size - 1 : @ptr - 1)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
while @cells[@ptr] != 0
	@ptr += 1
	@cells.push(0) if @ptr == @cells.length
	while @cells[@ptr] != 0
		@cells[@ptr] = STDIN.getc
@cells[@ptr] = 0 unless @cells[@ptr]
		@ptr += 1
		@cells.push(0) if @ptr == @cells.length
		@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
end
@ptr += 1
@cells.push(0) if @ptr == @cells.length
@ptr += 1
@cells.push(0) if @ptr == @cells.length
end
@ptr = (@ptr == 0 ? @cells.size - 1 : @ptr - 1)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
print @cells[@ptr].chr if @cells[@ptr]
@ptr += 1
@cells.push(0) if @ptr == @cells.length
@ptr += 1
@cells.push(0) if @ptr == @cells.length
print @cells[@ptr].chr if @cells[@ptr]
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
print @cells[@ptr].chr if @cells[@ptr]
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
print @cells[@ptr].chr if @cells[@ptr]
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
@cells[@ptr] = (@cells[@ptr] > 0 ? @cells[@ptr] - 1 : 255)
print @cells[@ptr].chr if @cells[@ptr]
@ptr += 1
@cells.push(0) if @ptr == @cells.length
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
print @cells[@ptr].chr if @cells[@ptr]
@ptr += 1
@cells.push(0) if @ptr == @cells.length
@cells[@ptr] = (@cells[@ptr] < 255 ? @cells[@ptr] + 1 : 0)
print @cells[@ptr].chr if @cells[@ptr]
