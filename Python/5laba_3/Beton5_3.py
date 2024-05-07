inputFile = open("input3.txt", "r")
inputList = [i.split() for i in inputFile.readlines()]
inputFile.close()

inputList.sort(key = lambda kid: kid[2])
theYoungestFile = open("output_youngest3.txt", "w")
theYoungestFile.write(inputList[0][0] + " " + inputList[0][1] + " " + str(inputList[0][2]))
theYoungestFile.close()

theOldestFile = open("output_oldest3.txt", "w")
theOldestFile.write(inputList[-1][0] + " " + inputList[-1][1] + " " + str(inputList[-1][2]))
theOldestFile.close()
