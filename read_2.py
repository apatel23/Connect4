FI = open("simple1_simple4.txt")


winC = 0
lossC = 0
tieC = 0
totalC = 0
numMoves = 0

apple=False

old_depth = 0

for line in FI:

	if line[0] == '\n':
		continue

	if line[0] == 'S':

		a = line.split()
		
		depth = int(a[4])

		if( depth == old_depth):
			apple=True
		else:
			apple=False

		if(depth != old_depth and old_depth != 0):
			print("depth," + str(old_depth))
			print("win," + str( lossC/totalC))
			print("lost,"+str( winC/totalC))
			print("tie," +str(tieC/totalC))
			print("Avg Moves,"+str(numMoves/totalC))
			print("Games Played,"+str(totalC))
			print("\n")

			winC = 0
			lossC = 0
			tieC = 0
			totalC = 0
			numMoves = 0

		old_depth = depth

		continue
	theLine = line.split(',')
	totalC = totalC + 1
	#print(theLine)
	numMoves = numMoves + int(theLine[2])
	if (apple):
		if theLine[0] == 'X':
			winC = winC + 1

		if theLine[0] == 'O':
			lossC = lossC + 1

		if theLine[0] == '-':
			tieC = tieC + 1
	else:
		if theLine[0] == 'X':
			lossC = lossC + 1

		if theLine[0] == 'O':
			winC = winC + 1

		if theLine[0] == '-':
			tieC = tieC + 1

