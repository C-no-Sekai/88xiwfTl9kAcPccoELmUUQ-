import os
total = 0
for i in os.listdir("."):
	if (len(i.split('.')) == 2) and (i.split('.')[1] == "cpp" or i.split('.')[1] == "h" or i.split(".")[1]=="ui" or i.split(".")[1] == "pro"):
		if i in ["test.ui", "transfer.ui"]: continue
		with open(i, 'r') as f:
			total += (f.read()).count("\n")
print(total)