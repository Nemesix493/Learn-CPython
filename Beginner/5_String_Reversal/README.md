# String Reversal
## Exercise Statement

Write a CPython function that takes a string as input and reverses its order (e.g., "hello" becomes "olleh").

Name the package `CPythonLearn5` and the function `string_reverse`.

The unittest need to import the function like:
```Python
    from CPythonLearn5 import string_reverse
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