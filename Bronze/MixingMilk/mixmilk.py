

with open("mixmilk.in", "r") as f:
    input_content = f.read()
    input_lines = input_content.split('\n')
    cap_ar = []
    milk_ar = []
    for i in range(3):
	line_items = input_lines[i].split(' ')
        cap = int(line_items[0])
	milk = int(line_items[1])
	cap_ar.append(cap)
  	milk_ar.append(milk)


for i in range(3):
    print(cap_ar[i], milk_ar[i])


