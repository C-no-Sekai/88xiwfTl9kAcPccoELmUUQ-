import os

files = list(os.listdir("."))
total = 0
totalWords = 0
totalChars = 0
for i in files:
    if (len(i.split('.')) == 2) and (i.split('.')[1] == "cpp" or i.split('.')[1] == "h"):
        with open(i, 'r') as f:
            temp = f.read()
            totalChars += len(temp)
            totalWords += temp.count(" ")
            total += temp.count("\n")

print("Total Lines Written:", total)
print("Total Words Written:", totalWords)
print("Total Chars Written:", totalChars)
