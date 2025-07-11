let board, n, solutions, messageElement, solutionsElement;

function isSafe(board, row, col) {
    for (let i = 0; i < col; i++) {
        if (board[row][i] === 1) return false;
    }
    for (let i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] === 1) return false;
    }
    for (let i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] === 1) return false;
    }
    return true;
}

async function solveNQueens(board, col) {
    if (col >= n) {
        solutions.push(board.map(row => [...row]));  // Save a copy of the board
        return false;  // Continue to find all solutions
    }

    let solutionFound = false;
    for (let i = 0; i < n; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            await drawBoard(board);
            if (await solveNQueens(board, col + 1)) {
                solutionFound = true;
            }
            board[i][col] = 0;
            await drawBoard(board);
        }
    }

    messageElement.innerHTML = solutionFound ? `Solution exists in iteration ${col}` : `No solution in iteration ${col}`;
    return false;
}

function drawBoard(board) {
    return new Promise(resolve => {
        const boardElement = document.getElementById('board');
        boardElement.style.gridTemplateColumns = `repeat(${n}, 50px)`;
        boardElement.innerHTML = '';
        for (let row = 0; row < n; row++) {
            for (let col = 0; col < n; col++) {
                const cell = document.createElement('div');
                cell.classList.add('cell');
                cell.classList.add((row + col) % 2 === 0 ? 'white' : 'black');
                if (board[row][col] === 1) {
                    cell.classList.add('queen');
                    cell.textContent = 'Q';
                }
                boardElement.appendChild(cell);
            }
        }
        setTimeout(resolve, 500);  // Adjust the delay for better visualization
    });
}

async function startVisualization() {
    n = parseInt(document.getElementById('n-input').value);
    if (isNaN(n) || n <= 0) {
        alert('Please enter a valid number');
        return;
    }

    messageElement = document.getElementById('message');
    solutionsElement = document.getElementById('solutions');
    messageElement.innerHTML = '';
    solutionsElement.innerHTML = '';
    board = Array.from({ length: n }, () => Array(n).fill(0));
    solutions = [];
    await solveNQueens(board, 0);

    if (solutions.length === 0) {
        messageElement.innerHTML = 'No solution exists';
    } else {
        messageElement.innerHTML = `Found ${solutions.length} solution(s)`;
        solutions.forEach((solution, index) => {
            const solutionBoard = document.createElement('div');
            solutionBoard.classList.add('board');
            solutionBoard.style.gridTemplateColumns = `repeat(${n}, 50px)`;
            solution.forEach(row => {
                row.forEach(cell => {
                    const cellElement = document.createElement('div');
                    cellElement.classList.add('cell');
                    cellElement.classList.add((row + cell) % 2 === 0 ? 'white' : 'black');
                    if (cell === 1) {
                        cellElement.classList.add('queen');
                        cellElement.textContent = 'Q';
                    }
                    solutionBoard.appendChild(cellElement);
                });
            });
            solutionsElement.appendChild(document.createElement('hr'));
            solutionsElement.appendChild(solutionBoard);
        });
    }
}
