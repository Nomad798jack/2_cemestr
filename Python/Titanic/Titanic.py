import csv
import random
import os

Csvfile = "Titanic.csv"

File = open("Titanic.csv", "r", newline='')
Reader = csv.DictReader(File)
data = []
for str in Reader:
    data.append(str)
File.close()

def Show(*, type = "top", number = 5, separator = '|'):
    if number > len(data):
        print("Error: No enough lines")
        return

    if type == "top": show_index = [i for i in range(number)]

    elif type == "random":
        show_index = []
        for i in range(number): show_index.append(random.randint(0, len(data)))

    elif type == "bottom": show_index  = [i for i in range(len(data)-number,len(data))]

    else:
        print("Error: Wrong type")
        return
    
    Width = {}
    for keys in data[0]:
        Width[keys] = len(keys)
    for i in show_index:
        for keys in data[i]:
            Width[keys] = max(len(data[i][keys]),Width[keys])
    header = [keys for keys in data[0]]

    for keys in Width:
        if keys != header[len(header) - 1]:
            print((Width[keys] - len(keys)) * " " + keys, end = separator)
        else:
            print((Width[keys] - len(keys)) * " " + keys)

    for i in show_index:
        for keys in data[i]:
            if keys != header[len(header) - 1]:
                print((Width[keys] - len(data[i][keys])) * " " + data[i][keys], end = separator)
            else:
                print((Width[keys] - len(data[i][keys])) * " " + data[i][keys])

def Info():
    noempty = {}
    for keys in data[0]:
        noempty[keys] = 0
    for i in data:
        for keys in i:
            if i[keys] != "": noempty[keys] += 1

    valueType = {"PassengerId":"int", "Survived":"bool", "Pclass":"int",  "Name":"str",  "Sex":"str", "Age":"float",  "SibSp":"int",  "Parch":"int",  "Ticket":"str",  "Fare":"float", "Cabin":"str", "Embarked":"str"}    
    print(len(data), "x" , len(data[0]), sep = "")

    for keys in noempty: print(keys, noempty[keys], valueType[keys], sep = "|")


def DelNaN():
    i = 0
    while(i != len(data)):
        delete = 0
        for keys in data[i]:
            if data[i][keys] == "":
                delete = 1
                break
        if delete: data.pop(i)
        else: i+=1

def MakeDS():
    if not os.path.exists("workdata"): os.mkdir("workdata")
    if not os.path.exists("workdata/Learning"): os.mkdir("workdata/Learning")
    if not os.path.exists("workdata/Testing"): os.mkdir("workdata/Testing")

    FilenameTrain = "workdata/Learning/train.csv"
    FilenameTest = "workdata/Testing/test.csv"

    File_train = open(FilenameTrain, "w", newline = "")
    File_test = open(FilenameTest, "w", newline = "")

    header = [keys for keys in data[0]]
    Writer_train = csv.DictWriter(File_train, fieldnames = header)
    Writer_test = csv.DictWriter(File_test, fieldnames = header)

    Writer_train.writeheader()
    Writer_test.writeheader()

    for i in data:
        seed = random.randint(1, 10)
        if seed <= 7: Writer_train.writerow(i)
        else: Writer_test.writerow(i)

    File_train.close()
    File_test.close()


Show()
Info()
DelNaN()
MakeDS()
