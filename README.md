NUMPLAY - Memory Game

A fun console-based memory game written in C++. NUMPLAY challenges players to memorize and recall randomly generated sequences of characters. The game supports both single-player and multiplayer (group) modes, with increasing difficulty as levels progress.

🎮 Features
🔢 Random sequences with digits, letters, and special characters (based on level).
👤 Single-player and 👥 Group mode support.
📈 Dynamic difficulty scaling as levels increase.
❤ Players get 3 chances before elimination.
🏆 Displays individual and group scores with accuracy percentage.
🎯 Motivational feedback (e.g., "Keep practicing!", "Outstanding memory!").

🚀 How to Run

🖥 Option 1: Run in Terminal (g++ Compiler)

Make sure you have g++ installed.
Compile the program:
g++ numplay.cpp -o numplay
Run the program:
./numplay

📝 Option 2: Run in Visual Studio Code (VS Code)

1. Open the project folder in VS Code.
2. Install the C/C++ extension by Microsoft (if not already installed).
3. Open the file numplay.cpp.
4. Click on the Run ▶ button at the top-right corner of the editor, or press Ctrl + F5 to run without debugging.
5. The game will run inside the VS Code integrated terminal.



📖 Game Rules

1. Choose Single (S) or Group (G) mode.
2. Enter player names.
3. At each level:
A random sequence is shown for a few seconds.
Players must type the exact sequence from memory.
4. Correct answers = +10 points.
5. Wrong answers = lose one chance (3 total).
6. Game ends when all players run out of chances.

🧠 Difficulty Levels

Level 1–5: Digits only.
Level 6–10: Digits + Letters.
Level 11+: Digits + Letters + Special Characters.

🏅 Example Output

===================================
   Welcome to NUMPLAY - A Memory Game
===================================
Play in Single (S) or Group (G) mode? S
Enter your name: Alex
Player: Alex
Memorize this sequence: 4aB7
(Wait for 3 seconds...)
Alex, enter the sequence: 4aB7
Correct!

===== Final Results =====
Alex → Score: 50 | Accuracy: 85%
Impressive memory, Alex!
Thanks for playing NUMPLAY!

📌 Future Improvements
Add difficulty selection before starting.
Support for custom sequence display time.
Add a leaderboard system.
Cross-platform GUI version.

📜 License
This project is open-source under the MIT License.


---

✅ This version is now beginner-friendly, works for both Terminal users and VS Code users, and looks polished for GitHub.

Do you also want me to add a cool badge section at the top (like “Built with C++ | g++ Compiler | Works in VS Code”) to make your README look even more professional?
