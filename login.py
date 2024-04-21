from flask import Flask, request, jsonify, session, redirect, url_for, render_template
import subprocess

app = Flask(__name__)
app.secret_key = 'your_secret_key'

# Authentication routes
@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        # Check user credentials and authenticate user
        # Set session variable indicating the user is authenticated
        session['logged_in'] = True
        return redirect(url_for('todo_list'))
    return render_template('login.html')

@app.route('/logout')
def logout():
    session.pop('logged_in', None)
    return redirect(url_for('login'))

# To-Do list routes
@app.route('/todo_list')
def todo_list():
    if 'logged_in' not in session:
        return redirect(url_for('login'))
    # Proceed to display the to-do list
    result = subprocess.run(['./todo_program', 'display'], capture_output=True, text=True)
    todo_list = result.stdout.splitlines()
    return render_template('todo_list.html', todo_list=todo_list)

@app.route('/add_task', methods=['POST'])
def add_task():
    if 'logged_in' not in session:
        return jsonify({"error": "Not logged in"})
    # Process adding task
    return jsonify({"message": "Task added successfully"})

# Other to-do list routes (mark_task_complete, etc.) would follow a similar pattern

if __name__ == '__main__':
    app.run(debug=True)
