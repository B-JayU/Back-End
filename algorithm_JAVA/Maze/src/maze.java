
public class maze {
	
	class Point{
		int x, y;
	}
	
	static Point[] stack = new Point[100];
	
	private static int N = 8;
	private static int [][] maze = {
			{0,0,0,0,0,0,0,1},
			{0,1,1,0,1,1,0,1},
			{0,0,0,1,0,0,0,1},
			{0,1,0,0,1,1,0,0},
			{0,1,1,1,0,0,1,1},
			{0,1,0,0,0,1,0,1},
			{0,0,0,1,0,0,0,1},
			{0,1,1,1,0,1,0,0}
	};
	
	private static int [][] visited = {
			{0,0,0,0,0,0,0,1},
			{0,1,1,0,1,1,0,1},
			{0,0,0,1,0,0,0,1},
			{0,1,0,0,1,1,0,0},
			{0,1,1,1,0,0,1,1},
			{0,1,0,0,0,1,0,1},
			{0,0,0,1,0,0,0,1},
			{0,1,1,1,0,1,0,0}
	};
	
	// start : (0,0)
	// exit : (N-1, N-1)
	
	// For Maze array
	private static final int PATHWAY_COLOR = 0; // white
	private static final int WALL_COLOR = 1;    // blue
	
	// For visited array
	private static final int BLOCKED_COLOR = 2; // red
	private static final int PATH_COLOR = 3;    // green
	
	private static int stackTop = -1;
	
	public static void main(String[] args) {
		
		boolean answer;
		
		answer = findWay(0,0);
		System.out.println(answer);
	}
	
	public static boolean findWay(int x, int y) {
		
		if (x < 0 || y < 0 || x >=N || y >=N)
			return false;
		else if(x == N-1 && y == N-1) {
			maze[x][y] = PATH_COLOR;
			//stack[++stackTop].x = x;
			//stack[stackTop].y = y;
			return true;
		}
		else if(maze[x][y] == WALL_COLOR)
			return false;
		else if(visited[x][y] == 1){
				return false;
		}else {
			maze[x][y] = PATH_COLOR;
			//stack[++stackTop].x = x;
			//stack[stackTop].y = y;
			visited[x][y] = 1;
			if (findWay(x-1,y) || findWay(x, y+1) || findWay(x+1, y) || findWay(x, y-1)) {
				return true;
			}
			maze[x][y] = BLOCKED_COLOR;
			//stackTop--;
			return false;
		}
	}
	
	public static void printMaze() {
		for (int i = stackTop; i >= 0; i--) {
			System.out.println("(" + stack[i].x + "," + stack[i].y + ")\n");
		}
	}
}
