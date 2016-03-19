# Connect4
Connect 4 for CSCI 498

By: Daniel Zarrini and Alex Patel

Game Origin: The classic Connect 4 or ‘Four in a Row’ has been enjoyed by children and adults for centuries. This game revolves around basic rules but the strategy can require some deep thought. It is not very clear exactly when the Connect 4 game first appeared. The earliest claimed ancestry is a legend surrounding early explorer named Captain James Cook. Cook was an 18th century explorer and navigator whose achievements in mapping the Pacific, New Zealand and Australia radically changed western perception of world geography. During his long sea voyage, Captain Cook was apparently often absent at evening and eventually the crew began to joke that he must have a mistress in the cabin. When the crew later discovered that the Captain had simply been playing connect 4 with the ship’s scientists, the game became famous and the crew named it ‘The Captain’s Mistress’ and that was the first known history of connect 4. 

Connect 4: Connect 4 is a simple game with simple basic rules. It is a 2 player game where players choose a color and then take turns dropping colored discs from the top into a 7 column, 6 row vertically suspended grid. The pieces fall straight­down, occupying the next available space within the column. The objective of the game is to connect 4 of one’s pieces in a row, either vertically, horizontally, or diagonally before your opponent. 

Project Description: In this project we plan to model the basic strategy for this classic game and determine the optimal decision any one player can make. Connect 4 was created in 1974. Since then, it has been proven that the player to start the game (the player who plays first) can connect 4 of his or her pieces before the opponent if the player can play the correct strategy. For this project, our goal is to solve the strategy needed to guarantee the first player wins. There are few things to consider when solving for the strategy in Connect 4. The game contains perfect information, where the players have all the information about the moves already played. Additionally, Connect 4 is considered a zero­sum game. A zero­sum game is where one player’s advantage is the other player’s disadvantage. If you were to sum the total gains and losses of both players, the total would equal zero. 

Challenges and Approaches: Connect 4 can be implemented as a dynamic game where each player has perfect information and can map all the possible end states of the game. For a classic Connect 4 game with 6 rows and 7 columns, there are 4,531,985,219,092 possible positions. The game has been solved using artificial intelligence techniques such as minimax and negamax, with alpha­beta pruning optimizations included. Without performing much research our approach was to map all possible
end states of this game and use backward induction to force the computer to make the best moves and ultimately win the game. 

Results: In order to test the accuracy of our strategy, we plan to use a GUI­based Connect 4 game. The strategy will be represented by an algorithm that selects the column that will maximize the player’s utility and/or minimize the opponent’s utility because the end goal is to connect 4 discs in a row before the opponent. 


