import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class MazeSolverDFS extends Frame {

    private static final int CELL = 50;
    private static final int SIDE = 650;

    private int[][] maze;
    private int rows, cols;

    private int[] start;
    private int[] end;

    private Label msgLable;
    private final Button startBtn;
    private Button pauseBtn;
    private boolean isPaused = false;

    private boolean[][] visited;

    private java.util.List<int[]> path;
    
    private boolean showVisited = false;
    private boolean showFinalPath = false;

    public MazeSolverDFS(int[][] maze, int[] start, int[] end) {
    
        this.maze = maze;
        rows = this.maze.length;
        cols = this.maze[0].length;
        this.start = start;
        this.end = end;

        setLayout(new BorderLayout());

        Panel btnPanel = new Panel();
        btnPanel.setLayout(new FlowLayout());

        startBtn = new Button("Start DFS Traversal");
        pauseBtn = new Button("Pause");

        btnPanel.add(startBtn);
        btnPanel.add(pauseBtn);

        msgLable = new Label("Click on Start to begin", Label.CENTER);
        msgLable.setFont(new Font("Arial", Font.BOLD, 18));

        add(btnPanel, BorderLayout.NORTH);
        add(msgLable, BorderLayout.SOUTH);

        startBtn.addActionListener(e -> {
            
            msgLable.setText("DFS Traversing...");
            new Thread(this::startVisualization).start();
        });

        pauseBtn.addActionListener(e -> {
            isPaused = !isPaused;
            if (isPaused) {

                pauseBtn.setLabel("Resume");
                msgLable.setText("Visualization paused");
            } 
            else {
                
                pauseBtn.setLabel("Pause");
                msgLable.setText("DFS Traversing");
            }
        });

        setTitle("Maze Solver Visualization - DFS");
        setSize(SIDE, SIDE);
        setVisible(true);

        addWindowListener(new WindowAdapter() {
            @Override 
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    @Override
    public void paint(Graphics g) {
        int gridW = cols*CELL;
        int gridH = rows*CELL;
        int xOffset = (SIDE - gridW)/2;
        int yOffset = (SIDE - gridH)/2;

        // initial maze
        for (int r=0; r<rows; r++) {
            for (int c=0; c<cols; c++) {
                
                if (maze[r][c] == 1) {
                    g.setColor(new Color(54, 69, 79));
                }
                else {
                    g.setColor(Color.WHITE);
                }
                g.fillRect(xOffset + c*CELL, yOffset + r*CELL, CELL, CELL);
                
                g.setColor(Color.GRAY);
                g.drawRect(xOffset + c*CELL, yOffset + r*CELL, CELL, CELL);
            }
        }

        // traversal
        if (showVisited && visited != null) {
            
            g.setColor(new Color(135, 206, 250));
            
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    
                    if (visited[r][c] && !(r == start[0] && c == start[1]) && !(r == end[0] && c == end[1])) {
                        
                        g.fillRect(xOffset + c*CELL, yOffset + r*CELL, CELL, CELL);
                        
                        g.setColor(Color.GRAY);
                        g.drawRect(xOffset + c*CELL, yOffset + r*CELL, CELL, CELL);
                        
                        g.setColor(new Color(135, 206, 250));
                    }
                }
            }
        }

        // final path
        if (showFinalPath && path != null) {
            
            g.setColor(new Color(34, 240, 95));
            
            for (int[] p : path) {
                
                int r = p[0], c = p[1];
                
                if (!(r == start[0] && c == start[1]) && !(r == end[0] && c == end[1])) {
                
                    g.fillRect(xOffset + c*CELL, yOffset + r*CELL, CELL, CELL);
                
                    g.setColor(Color.GRAY);
                    g.drawRect(xOffset + c*CELL, yOffset + r*CELL, CELL, CELL);
                
                    g.setColor(new Color(34, 240, 95));
                }
            }
        }

        g.setColor(new Color(0, 128, 255));
        g.fillRect(xOffset + start[1]*CELL, yOffset + start[0]*CELL, CELL, CELL);
        
        g.setColor(Color.RED);
        g.fillRect(xOffset + end[1]*CELL,   yOffset + end[0]*CELL,   CELL, CELL);
    }

    private void delay(long ms) {
        try {
            Thread.sleep(ms);
            while (isPaused) {
                Thread.sleep(100);
            }
        } 
        catch (InterruptedException ie) {
            Thread.currentThread().interrupt();
        }
    }

    private void startVisualization() {
        
        visited = new boolean[rows][cols];
        path = new ArrayList<>();
        
        showVisited = true;
        showFinalPath = false;

        msgLable.setText("DFS started");

        boolean found = dfs(start[0], start[1]);

        if (found) {
            
            msgLable.setText("DFS complete: Path found.");
            delay(2000);
            
            showVisited = false;
            showFinalPath = true;
            
            repaint();
            msgLable.setText("Final path highlighted");
        } else {
            
            msgLable.setText("DFS complete: No path found.");
            delay(2000);
            
            showVisited = true;
            showFinalPath = false;
            
            repaint();
            msgLable.setText("No path exists for this maze");
        }
    }

    // explore all by dfs
    private boolean dfs(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) return false;
        if (maze[r][c] == 1 || visited[r][c]) return false;

        visited[r][c] = true;
        repaint();
        delay(750);

        if (r == end[0] && c == end[1]) {
            
            path.add(0, new int[]{r, c});
            return true;
        }

        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for (int[] d : dirs) {
            
            if (dfs(r + d[0], c + d[1])) {
                path.add(0, new int[]{r, c});
                return true; 
            }
        }

        return false;
    }


    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter rows: ");
        int r = sc.nextInt();
        
        System.out.print("Enter cols: ");
        int c = sc.nextInt();

        int[][] mazeInput = new int[r][c];
        
        int[] start = null;
        int[] end = null;
        int start_end = 0; // count of -1

        System.out.println("Enter maze (0=open, 1=wall, -1=start/end):");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                
                int val = sc.nextInt();
                
                if (val == -1) {
                    start_end++;
                
                    if (start_end == 1) {
                        start = new int[]{i, j};
                    } 
                    else if (start_end == 2) {
                        end = new int[]{i, j};
                    } 
                    else {
                        System.out.println("Error: More than 2 -1 values entered.");
                        return;
                    }
                    
                    mazeInput[i][j] = 0; 
                } 
                else {
                    mazeInput[i][j] = val;
                }
            }
        }

        if (start_end < 2) {
            System.out.println("Error: You must enter exactly 2 -1 values for start and end." + start_end);
            return;
        }

        new MazeSolverDFS(mazeInput, start, end);
    }
}
