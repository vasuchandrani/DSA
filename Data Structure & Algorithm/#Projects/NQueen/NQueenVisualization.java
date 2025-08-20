import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.List;

public class NQueenVisualization extends Frame {
    
    private static final int CELL = 50;
    private static final int SIDE = 650;
    
    private int N; 
    private int[][] board; 
    
    private Label msgLabel;
    private TextField inputText;
    private final Button startBtn;
    private Button pauseBtn;
    private boolean isPaused = false; 

    // stores all the solutions
    private List<int[][]> solutions; 

    public NQueenVisualization() {

        board = new int[4][4]; 
        N = 4;
        solutions = new ArrayList<>();

        // GUI layout
        setLayout(new BorderLayout());

        // control panel for buttons and input-field
        Panel btnPanel = new Panel();
        btnPanel.setLayout(new FlowLayout());

        Label inputLabel = new Label("Enter Queen:");
        inputText = new TextField("4", 2); 
        startBtn = new Button("Start");
        pauseBtn = new Button("Pause");

        btnPanel.add(inputLabel);
        btnPanel.add(inputText);
        btnPanel.add(startBtn);
        btnPanel.add(pauseBtn);

        // message panel  
        msgLabel = new Label("Click on Start to begin", Label.CENTER);
        msgLabel.setFont(new Font("Arial", Font.BOLD, 24)); 

        add(msgLabel, BorderLayout.SOUTH);
        add(btnPanel, BorderLayout.NORTH);

        // add action listners
        startBtn.addActionListener(e -> {
            
            try {
                int input = Integer.parseInt(inputText.getText());
            
                if (input > 0) {
                    N = input;
                    board = new int[N][N];
                    
                    solutions.clear(); 
                    msgLabel.setText("Visualization started");
                    new Thread(this::startVisualization).start();
                } 
                else {
                    msgLabel.setText("Invalid input! Please enter a valid number");
                }
            } catch (NumberFormatException ex) {
                msgLabel.setText("Invalid input! Please enter a valid number");
            }
        });
        pauseBtn.addActionListener(e -> {
            isPaused = !isPaused; 
            if (isPaused) {
                pauseBtn.setLabel("Resume");
                msgLabel.setText("Visualization paused");
            } 
            else {
                pauseBtn.setLabel("Pause");
                msgLabel.setText("Visualization started");
            }
        });

        setTitle("N-Queens Visualization");
        setSize(SIDE, SIDE);
        setVisible(true);

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }
    // ------
    @Override
    public void paint(Graphics g) {
        int boardSize = N*CELL; 
        int xPos = (SIDE - boardSize) / 2; 
        int yPos = (SIDE - boardSize) / 2; 

        // paint board 
        for (int row=0; row<N; row++) {
            for (int col=0; col<N; col++) {
                
                g.setColor((row + col) % 2 == 0 ? new Color(54, 69, 79) : new Color(135, 206, 250));
                g.fillRect(xPos + col*CELL, yPos + row*CELL, CELL, CELL);

                // Queen 
                if (board[row][col] == 1) {
                    g.setColor(Color.WHITE);
                    g.fillOval(xPos + col*CELL + 10, yPos + row*CELL + 10, CELL - 20, CELL - 20);
                }
            }
        }
    }
    // ------
    private void delay() {
        try {
            Thread.sleep(750); 
            while (isPaused) {
                Thread.sleep(100); 
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
    // ------   NQueen solve
    private boolean isSafe(int row, int col) {
        // same col
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 1) return false;
        }
        
        // diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) return false;
        }
        for (int i = row, j = col; i < N && j >= 0; i++, j--) {
            if (board[i][j] == 1) return false;
        }

        return true;
    }
    
    private void findAllSolutions(int col) {  
     
        // base-case
        if (col >= N) {
            int[][] solution = new int[N][N];
            for (int i = 0; i < N; i++) {
                System.arraycopy(board[i], 0, solution[i], 0, N);
            }
    
            solutions.add(solution);
            repaint();
            
            try {
                msgLabel.setText("Solution Found");
                Thread.sleep(1500);
                msgLabel.setText("Check for further solution"); 
                Thread.sleep(750); 
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
            return;
        }
        for (int i = 0; i < N; i++) {
            if (isSafe(i, col)) {
                board[i][col] = 1;
                repaint();
                delay();

                findAllSolutions(col + 1);

                board[i][col] = 0; 
                repaint();
                delay();
            }
        }
    }
    // -----
    private void startVisualization() {
        findAllSolutions(0);
        msgLabel.setText("Found " + solutions.size() + " solutions.");
        displaySolutions(); // Call the displaySolutions method after finding all solutions
    }
    // -----
    private void displaySolutions() {
        int count = 1; 
        for (int[][] solution : solutions) {
            board = solution;
            repaint();
            try {
                if (count == 1) {
                    msgLabel.setText("Displaying " + count + "st solution...");
                } else if (count == 2) {
                    msgLabel.setText("Displaying " + count + "nd solution...");
                } else if (count == 3) {
                    msgLabel.setText("Displaying " + count + "rd solution...");
                } else {
                    msgLabel.setText("Displaying " + count + "th solution...");
                }
                Thread.sleep(3000); 
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
            count++; 
        }
        count--;
        if (count > 0)
            msgLabel.setText("All solutions displayed, "+count+" solutions found for "+N+" Queens"); 
        else 
            msgLabel.setText("No solutions found for "+N+" Queens");
    }

    public static void main(String[] args) {
        new NQueenVisualization();
    }
}