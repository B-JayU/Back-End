package templateEx;

public class Player {
	
	
	// instance : level
	private PlayerLevel level;

	public Player() {
		level = new BeginnerLevel();
		level.showLevelMessage();
	}
	// method : getlevel
	public PlayerLevel getLevel() {
		return level;
	}

	// method : upgradeLevel(PlayerLevel)
	public void upgradeLevel(PlayerLevel level) {
		this.level = level;
		level.showLevelMessage();
	}
	
	// method : play()
	public void play(int count) {
		level.go(count);
	}
	
}
