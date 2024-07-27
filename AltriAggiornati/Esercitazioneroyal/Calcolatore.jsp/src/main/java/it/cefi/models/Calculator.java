package it.cefi.models;

import java.util.Stack;

public class Calculator {
    private Stack<Double> numbers;
    private Stack<String> operations;

    public Calculator() {
        numbers = new Stack<>();
        operations = new Stack<>();
    }

    public void addNumber(double number) {
        numbers.push(number);
    }

    public void addOperation(String operation) {
        while (!operations.isEmpty() && getPrecedence(operations.peek()) >= getPrecedence(operation)) {
            executeOperation();
        }
        operations.push(operation);
    }

    public void executeOperations() {
        while (!operations.isEmpty()) {
            executeOperation();
        }
    }

    private void executeOperation() {
        if (numbers.size() < 2) {
            throw new IllegalStateException("Not enough operands for operation");
        }
        if (operations.isEmpty()) {
            throw new IllegalStateException("No operation to execute");
        }
        double number1 = numbers.pop();
        double number2 = numbers.pop();
        String operation = operations.pop();

        switch (operation) {
            case "somma":
                numbers.push(number2 + number1);
                break;
            case "sottrazione":
                numbers.push(number2 - number1);
                break;
            case "moltiplicazione":
                numbers.push(number2 * number1);
                break;
            case "divisione":
                if (number1!= 0) {
                    numbers.push(number2 / number1);
                } else {
                    throw new ArithmeticException("Division by zero!");
                }
                break;
            default:
                throw new UnsupportedOperationException("Invalid operation!");
        }
    }

    public double getResult() {
        if (numbers.isEmpty()) {
            throw new IllegalStateException("No result available");
        }
        return numbers.pop();
    }

    private int getPrecedence(String operation) {
        switch (operation) {
            case "somma":
            case "sottrazione":
                return 1;
            case "moltiplicazione":
            case "divisione":
                return 2;
            default:
                return 0;
        }
    }
}