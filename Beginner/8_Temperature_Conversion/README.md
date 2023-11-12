# Temperature Conversion
## Exercise Statement

Write a CPython function that takes a temperature in degrees Celsius as input and converts it to degrees Fahrenheit using the formula: Fahrenheit = (Celsius * 9/5) + 32.


Name the package `CPythonLearn8` and the function `temperature_conversion`.

The unittest need to import the function like:
```Python
    from CPythonLearn8 import temperature_conversion
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