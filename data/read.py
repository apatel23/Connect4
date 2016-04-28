FI = open("simple_data_depths_2.txt")


winC = 0
lossC = 0
tieC = 0
totalC = 1
numMoves = 0

oldfp = ""
oldsp = ""

for line in FI:

	if line[0] == '\n':
		continue

	if line[0] == 'P':

		a = line.split()
		fp = a[3]
		sp = a[7]

		print(oldfp+","+oldsp)
		print("win," + str( winC/totalC))
		print("lost,"+str( lossC/totalC))
		print("tie," +str(tieC/totalC))
		print("Avg Moves,"+str(numMoves/totalC))
		print("Total Moves,"+str(totalC))
		print()

		winC = 0
		lossC = 0
		tieC = 0
		totalC = 0
		numMoves = 0

		oldfp = fp
		oldsp = sp

		continue
	theLine = line.split(',')
	totalC = totalC + 1
	#print(theLine)
	numMoves = numMoves + int(theLine[2])
	if theLine[0] == 'X':
		winC = winC + 1

	if theLine[0] == 'O':
		lossC = lossC + 1

	if theLine[0] == '-':
		tieC = tieC + 1
