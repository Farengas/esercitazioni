// ESERCIZIO_01 C++
#include <iostream>
#include <ctime>

constexpr int MAX_SIZE { 10 };

void generateArray(int array[MAX_SIZE]);
void sortArray(int array[MAX_SIZE]);

int main()
{
    int array[MAX_SIZE];
    srand(time(NULL));

    generateArray(array);
    sortArray(array);

    return EXIT_SUCCESS;
}

void generateArray(int array[MAX_SIZE])
{
    // Generazione e stampa di un array di numeri casuali 0 e 1.
    for (int i { 0 }; i < MAX_SIZE; i++)
        array[i] = rand() % 2;

    std::cout << "Generated array: { ";
    for (int i { 0 }; i < MAX_SIZE; i++)
        std::cout << array[i] << ' ';
    std::cout << "}\n";
}

void sortArray(int array[MAX_SIZE])
{
    // Riordinamento dei numeri casuali.
    int temp { 0 };
    for (int i { 0 }; i < MAX_SIZE; i++)
    {
        if (array[i] == 0)
        {
            std::swap(array[temp], array[i]);
            temp++;
        }
    }

    // Stampa dell'array di numeri casuali riordinati.
    std::cout << "Sorted array:\t { ";
    for (int i { 0 }; i < MAX_SIZE; i++)
        std::cout << array[i] << ' ';

    std::cout << "}\n";
}

/* ESERCIZIO_01 Java[JSP]
 * Index.jsp
*/
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.regex.Pattern, java.util.regex.Matcher, java.util.ArrayList"%>
<!DOCTYPE html>
<html>
<head>
    <title>Mathematical Parser</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <style>
        .custom-button {
            width: auto;
            height: 40px;
        }
        .container {
            margin-top: 50px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1 style="font-size: 26px;">Enter a mathematical expression:</h1>
        <form method="post">
            <div class="d-flex">
                <div class="mb-3 flex-grow-1 mr-3">
                    <input type="text" name="input" id="txtInput" class="form-control" placeholder="Enter the expression" style="font-size: 18px;">
                </div>
                <button type="submit" class="custom-button btn btn-primary">Submit</button>
            </div>
        </form>
        
        <%
            String input = request.getParameter("input");
            if (input != null && !input.trim().isEmpty()) {
                input = input.toLowerCase();
                Pattern pattern = Pattern.compile("([-+]?\\d+\\.?\\d*)|([+*\\-x/:])");
                Matcher matcher = pattern.matcher(input);

                ArrayList<String> tokens = new ArrayList<>();
                while (matcher.find()) {
                    tokens.add(matcher.group());
                }
                
                try {
                    if (tokens.size() < 3) {
                        out.println("<div class='alert alert-danger mt-3' role='alert'><strong>Error: the input does not contain a valid mathematical expression.</strong></div>");
                    } else {
                        double result = Double.parseDouble(tokens.get(0));
                        for (int i = 1; i < tokens.size(); i += 2) {
                            String operator = tokens.get(i);
                            double nextNumber = Double.parseDouble(tokens.get(i + 1));
                            switch (operator) {
                                case "+":
                                    result += nextNumber;
                                    break;
                                case "-":
                                    result -= nextNumber;
                                    break;
                                case "*":
                                case "x":
                                    result *= nextNumber;
                                    break;
                                case "/":
                                case ":":
                                    if (nextNumber != 0) {
                                        result /= nextNumber;
                                    } else {
                                        throw new ArithmeticException("Division by zero.");
                                    }
                                    break;
                                default:
                                    throw new IllegalArgumentException("Unsupported operation: " + operator);
                            }
                        }
                        out.println("<div class='alert alert-success mt-3' role='alert'><strong>Result: " + result + "</strong></div>");
                    }
                } catch (Exception e) {
                    out.println("<div class='alert alert-danger mt-3' role='alert'><strong>Error: " + e.getMessage() + "</strong></div>");
                }
            } else if (request.getMethod().equalsIgnoreCase("POST")) {
                out.println("<div class='alert alert-danger mt-3' role='alert'><strong>Error: the input is empty.</strong></div>");
            }
        %>
    </div>
</body>
</html>

/* ESERCIZIO_01 C# [WPF]
 * MainWindow.xaml.cs
*/
using System.Text.RegularExpressions;
using System.Windows;

namespace SquareCodeCipher;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }

    private string NormalizeText(string text)
    {
        string lowerText = text.ToLower();
        string normalizedText = Regex.Replace(lowerText, @"[^a-z]", "");
        return normalizedText;
    }

    private (int, int) CalculateRectangleSize(int length)
    {
        int columns = (int)Math.Ceiling(Math.Sqrt(length));
        int rows = (int)Math.Floor(Math.Sqrt(length));
        while (columns * rows < length)
        {
            if (columns > rows)
            {
                rows++;
            }
            else
            {
                columns++;
            }
        }
        return (rows, columns);
    }

    private string Encrypt(string text, int rows, int columns)
    {
        char[,] rectangle = new char[rows, columns];
        for (int i = 0; i < text.Length; i++)
        {
            int row = i / columns;
            int column = i % columns;
            rectangle[row, column] = text[i];
        }

        string encryptedText = "";
        for (int column = 0; column < columns; column++)
        {
            for (int row = 0; row < rows; row++)
            {
                if (rectangle[row, column] != '\0')
                {
                    encryptedText += rectangle[row, column];
                }
            }
            encryptedText += " ";
        }

        return encryptedText.Trim();
    }

    private void EncryptButton(object sender, RoutedEventArgs e)
    {
        string inputText = InputTextBox.Text;
        string normalizedText = NormalizeText(inputText);
        (int rows, int columns) = CalculateRectangleSize(normalizedText.Length);
        string encryptedText = Encrypt(normalizedText, rows, columns);
        OutputTextBox.Text = encryptedText;
    }

}
// MainWindow.xaml
<Window x:Class="SquareCodeCipher.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="Square Code Cipher" Height="350" Width="525" Background="#2C2255" WindowStartupLocation="CenterScreen" ResizeMode="NoResize">
    <Grid>
        <Label Content="Inserisci il testo da criptare:" HorizontalAlignment="Left" VerticalAlignment="Top" Margin="10,7,0,0" Foreground="White"/>
        <TextBox Name="InputTextBox" Height="100" Width="490" HorizontalAlignment="Left" VerticalAlignment="Top" Margin="10,33,0,0" Background="#1C1C1C" Foreground="White" TextWrapping="Wrap" AcceptsReturn="True"/>
        <Button Content="Cripta" HorizontalAlignment="Left" VerticalAlignment="Top" Margin="10,140,0,0" Width="75" Background="#F7941E" Foreground="#2C2255" Click="EncryptButton"/>
        <Label Content="Testo criptato:" HorizontalAlignment="Left" VerticalAlignment="Top" Margin="10,173,0,0" Foreground="White"/>
        <TextBox Name="OutputTextBox" Height="100" Width="490" HorizontalAlignment="Left" VerticalAlignment="Top" Margin="10,199,0,0" Background="#1C1C1C" Foreground="White" TextWrapping="Wrap" AcceptsReturn="True" IsReadOnly="True"/>
    </Grid>
</Window>