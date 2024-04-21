const express = require('express');
const bodyParser = require('body-parser');
const { spawn } = require('child_process');

const app = express();
const PORT = process.env.PORT || 3000;

app.use(bodyParser.json());

// Route to add a task
app.post('/addTask', (req, res) => {
    const description = req.body.description;

    const process = spawn('./todo_program', ['add', description]);

    process.on('close', (code) => {
        if (code === 0) {
            res.send({ message: 'Task added successfully' });
        } else {
            res.status(500).send({ error: 'Failed to add task' });
        }
    });
});

// Other routes for CRUD operations would follow a similar pattern

app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
