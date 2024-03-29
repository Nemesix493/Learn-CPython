# Fibonacci Calculation
## Exercise Statement

Write a CPython function that generates the Fibonacci sequence up to a given number.


Name the package `CPythonLearn11` and the function `fibonacci_calculation`.

The unittest need to import the function like:
```Python
    from CPythonLearn11 import fibonacci_calculation
```

## Testing your code

You can either use Docker or a virtual environment to run the tests:
- [Docker Documentation](https://docs.docker.com/)
- [venv Documentation](https://docs.python.org/3/library/venv.html)

### Docker

1. In the Dockerfile change the `RUN` instruction that install the package `my_solution` to your solution:
```Dockerfile
    RUN pip install /app/<path-to-your-solution>
```
2. Build your Docker image:
```bash
    docker build -t <your-image-name> .
```
3. Run the image:
```bash
    docker run <your-image-name>
```

### Virtual Environment

1. Activate your virtual environment.
2. Install your package:
```bash
    python3 -m pip install <path-to-your-solution>
```
3. Run the tests:
```bash
    python3 -m unittest
```