import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void printMaze(int[][] maze) {
        for (int[] x : maze) {
            for (int y : x) {
                System.out.print(y + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void backtrack(int row, int col, int[][] maze) {
        int[] directionRow = {-1, 0, 1, 0};
        int[] directionCol = {0, 1, 0, -1};
        maze[row][col] = 9;
        if ((row == 0 || col == 0) || (row == maze.length - 1 || col == maze[row].length - 1)) {
            printMaze(maze);
            System.exit(1);
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nextRow = row + directionRow[i];
            int nextCol = col + directionCol[i];
            if (maze[nextRow][nextCol] == 0) {
                backtrack(nextRow, nextCol, maze);
            }
        }
        maze[row][col] = 0;
    }

    public static void makeEscape(int row, int col, int[][] maze) {
        Random random = new Random();
        int[] directionRow = {-1, 0, 1, 0};
        int[] directionCol = {0, 1, 0, -1};
        maze[row][col] = 0;
        if ((row == 0 || col == 0) || (row == maze.length - 1 || col == maze[row].length - 1)) {
            return;
        }
        int x = random.nextInt(3);
        int nextRow = row + directionRow[x];
        int nextCol = col + directionCol[x];
        makeEscape(nextRow, nextCol, maze);
    }

    public static void fillMaze(int[][] maze) {
        Random random = new Random();
        for (int row = 0; row < maze.length; row++) {
            for (int col = 0; col < maze.length; col++) {
                maze[row][col] = 1;
            }
        }
        makeEscape(maze.length / 2, maze[0].length / 2, maze);
        System.out.println("Created exit:");
        printMaze(maze);
        for (int row = 0; row < maze.length; row++) {
            for (int col = 0; col < maze[row].length; col++) {
                if (!((row == 0 || col == 0) || (row == maze.length - 1 ||
                        col == maze[row].length - 1)) && maze[row][col] != 0) {
                    maze[row][col] = random.nextInt(2);
                }
            }
        }
    }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    System.out.print("Enter the size of the maze: ");
    int n = scan.nextInt();
    int[][] maze = new int[n][n];
    fillMaze(maze);
    System.out.println("Maze:");
    printMaze(maze);
    System.out.println();
    System.out.println("Our escape:");
    backtrack(n / 2, n / 2, maze);
    System.out.println("There is no way out");

}
}

 