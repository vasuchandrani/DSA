import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.List;

public class NQueenVisualization extends Frame {
    
    private static final int CELL = 50;
    private static final int SIDE = 650;
    private int N; 
    private int[][] board; 
    private Label messageLabel;
    private TextField inputField;
    private Button startButton, pauseButton;
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
        Panel controlPanel = new Panel();
        controlPanel.setLayout(new FlowLayout());

        Label inputLabel = new Label("Enter Queen:");
        inputField = new TextField("4", 2); 
        startButton = new Button("Start");
        pauseButton = new Button("Pause");

        controlPanel.add(inputLabel);
        controlPanel.add(inputField);
        controlPanel.add(startButton);
        controlPanel.add(pauseButton);

        // message panel  
        messageLabel = new Label("Click 'Start' to begin", Label.CENTER);
        messageLabel.setFont(new Font("Arial", Font.BOLD, 24)); 

        add(messageLabel, BorderLayout.SOUTH);
        add(controlPanel, BorderLayout.NORTH);

        // add action listners
        startButton.addActionListener(e -> {
            try {
                int input = Integer.parseInt(inputField.getText());
                if (input > 0) {
                    N = input;
                    board = new int[N][N];
                    
                    solutions.clear(); 
                    messageLabel.setText("Visualization started");
                    new Thread(this::startVisualization).start();
                } else {
                    messageLabel.setText("Invalid input! Please enter a valid number");
                }
            } catch (NumberFormatException ex) {
                messageLabel.setText("Invalid input! Please enter a valid number");
            }
        });
        pauseButton.addActionListener(e -> {
            isPaused = !isPaused; 
            if (isPaused) {
                pauseButton.setLabel("Resume");
                messageLabel.setText("Visualization paused");
            } else {
                pauseButton.setLabel("Pause");
                messageLabel.setText("Visualization resumed");
            }
        });

        setTitle("N-Queens Visualization");
        setSize(SIDE, SIDE);
        setVisible(true);

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }
    // ------
    public void paint(Graphics g) {
        int boardSize = N * CELL; 
        int xOffset = (SIDE - boardSize) / 2; 
        int yOffset = (SIDE - boardSize) / 2; 

        // paint board 
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                g.setColor((row + col) % 2 == 0 ? new Color(54, 69, 79) : new Color(135, 206, 250));
                g.fillRect(xOffset + col * CELL, yOffset + row * CELL, CELL, CELL);

                // Queen 
                if (board[row][col] == 1) {
                    g.setColor(Color.WHITE);
                    g.fillOval(xOffset + col * CELL + 10, yOffset + row * CELL + 10, CELL - 20, CELL - 20);
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
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 1) return false;
        }
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
                messageLabel.setText("Solution Found");
                Thread.sleep(1500);
                messageLabel.setText("Check for further solution"); 
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
        messageLabel.setText("Found " + solutions.size() + " solutions.");
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
                    messageLabel.setText("Displaying " + count + "st solution...");
                } else if (count == 2) {
                    messageLabel.setText("Displaying " + count + "nd solution...");
                } else if (count == 3) {
                    messageLabel.setText("Displaying " + count + "rd solution...");
                } else {
                    messageLabel.setText("Displaying " + count + "th solution...");
                }
                Thread.sleep(3000); 
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
            count++; 
        }
        count--;
        if (count > 0)
            messageLabel.setText("All solutions displayed, "+count+" solutions found for "+N+" Queens"); 
        else 
            messageLabel.setText("No solutions found for "+N+" Queens");
    }

    public static void main(String[] args) {
        new NQueenVisualization();
    }
}