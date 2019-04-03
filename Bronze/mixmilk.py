

with open("mixmilk.in", "r") as f:
    input_content = f.read()
    input_lines = input_content.split('\n')
    cows = []
    buckets = []
    for i in range(3):
	line_items = input_lines[i].split(' ')
        cow = line_items[0]
	bucket = line_items[1]
	cows.append(cow)
  	buckets.append(bucket)


for i in range(3):
    print(cows[i], buckets[i])


