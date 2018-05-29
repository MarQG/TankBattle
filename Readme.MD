# Tank Game GDD:

## The Concept:
	Single Tank vs Single Tank in an open terrain. AI or Other Player controls second tank.
	Position self within range and defeat your opponent.
	Tank battle is an open-world head-to-head tank combat game.
	Terrain will be used for tactical advantage
	The focus will be on flow and feel

## Rules:
	You win when the other players tank is destroyed. You lose when your tank is destroyed
	You can fire the main cannon. You can move forward, backward, rotate left, rotate right, 
	Turn the turret left or right independant of the tank body and elevate the turret up or
	Down.
	You can move anywhere in the terrain, which is surrounded by mountains (barrier)
	Both players start with finite health and ammo
	Each Direct Hit takes away health
	The last player standing wins.

## Requirements:
### Tanks Models:
### Static Mesh:
		Simple Tank comprising tracks, body, turret and barrel
### Textures
### Music 
###	Exposion Effects
###	Game Map
###	UI Graphics
		Start Button
		Exit Button
		Reset Screen
		Game Over Screen
		Play Again Button
###	HUD:
		Crosshair
		HP Bars
		
###	Sound Effects:
		Cannon Shot
		Cannon Impact
		Explosion
		Tank Tracks
		Tank Engine
		Tank Hit
		Tank Turret Moving
		Tan Barrel Moving
		Background Music


## Notes:
	Iterate around a loop while making this game
	Constantly asking “whats least fun?”
	Remember not at AAA studio
	Let’s find the essence of fun

## Iterative Cycle:
	World -> Tank -> Controls -> Player 2 -> UI -> Back to World
