// ESERCIZIO_03 C++
#include <iostream>
#include <ctime>

constexpr int MAX_SIZE { 20 };

void generateArray(int array[MAX_SIZE]);
void checkArrayValue(int& number);
void findEqualsSumValues(int array[MAX_SIZE], int number);

int main()
{
    int array[MAX_SIZE];
    srand(time(NULL));
    int number { 0 };

    generateArray(array);
    checkArrayValue(number);
    findEqualsSumValues(array, number);

    return EXIT_SUCCESS;
}

void generateArray(int array[MAX_SIZE])
{
    // Generazione e stampa di un array di numeri interi casuali compresi tra 1 e 100.
    for (int i { 0 }; i < MAX_SIZE; i++)
        array[i] = 1 + rand() % 100;

    std::cout << "Generated array: { ";
    for (int i { 0 }; i < MAX_SIZE; i++)
        std::cout << array[i] << ' ';
    std::cout << "}\n";
}

void checkArrayValue(int& number)
{
    // Controllo del numero inserito da parte dell'utente.
    do
    {
        std::cout << "\n\nEnter a number (MIN 1, MAX 90): ";
        std::cin >> number;

        if (number < 1 || number > 90)
            std::cerr << "\nThe number must be between 1 and 90.\n";
    }
    while (number < 1 || number > 90);
}

void findEqualsSumValues(int array[MAX_SIZE], int number)
{
    // Ricerca e stampa delle coppie di valori nell'array la cui somma è pari al numero inserito dall'utente.
    bool checker { false };
    std::cout << "\nEquals summed values:\n";
    for (int i { 0 }; i < MAX_SIZE; i++)
    {
        for (int j { i + 1 }; j < MAX_SIZE; j++)
        {
            if (array[i] + array[j] == number)
            {
                checker = true;
                printf_s("%2d + %2d = %2d (position: %2d, %2d)\n", array[i], array[j], number, i, j);
            }
        }
    }
    if (!checker)
        std::cout << "There are no equals summed values.\n";
}

/* ESERCIZIO_03 Java [JSP]
 * Model 
*/
package it.cefi.models;

public class SquareCodeModel {
    private String phrase;
    private int columns;
    private int rows;
    private String[][] rectangle;
    private StringBuilder encryptedText;
    private StringBuilder blockedText;
	
    public void setPhrase(String phrase) {
        this.phrase = normalizeText(phrase);
        columns = calculateColumns(this.phrase.length());
        rows = calculateRows(this.phrase.length(), columns);
        rectangle = createRectangle(this.phrase, rows, columns);
        encryptedText = new StringBuilder();
        blockedText = new StringBuilder();
    }
	
    public void encodePhrase() {
        for (int j = 0; j < columns; j++) {
            for (int i = 0; i < rows; i++) {
                encryptedText.append(rectangle[i][j]);
            }
        }
        blockedText = new StringBuilder(splitIntoBlocks(encryptedText.toString(), columns));
    }
	
    public String getBlockedText() {
        return blockedText.toString().trim();
    }
	
    private String normalizeText(String text) {
        text = text.replaceAll("[^a-z]", "").toLowerCase();
        return text;
    }
	
    private int calculateColumns(int length) {
        int columns = (int) Math.sqrt(length);
        while (columns * (columns - 1) < length) {
            columns++;
        }
        return columns;
    }
	
    private int calculateRows(int length, int columns) {
        return (int) Math.ceil((double) length / columns);
    }
	
    private String[][] createRectangle(String text, int rows, int columns) {
        String[][] rectangle = new String[rows][columns];
        int index = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (index < text.length()) {
                    rectangle[i][j] = text.substring(index, index + 1);
                    index++;
                } else {
                    rectangle[i][j] = "";
                }
            }
        }
        return rectangle;
    }
	
    private String splitIntoBlocks(String text, int columns) {
        StringBuilder blockedText = new StringBuilder();
        for (int i = 0; i < text.length(); i += columns) {
            if (i + columns <= text.length()) {
                blockedText.append(text.substring(i, i + columns)).append(" ");
            } else {
                blockedText.append(text.substring(i));
            }
        }
        return blockedText.toString();
    }
}
// Controller
package it.cefi.controllers;

import java.io.IOException;
import it.cefi.models.SquareCodeModel;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class SquareCodeController extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Get the phrase from the request
        String phrase = request.getParameter("phrase");

        // Create and set up the model
        SquareCodeModel model = new SquareCodeModel();
        model.setPhrase(phrase);
        model.encodePhrase();

        // Get the encoded phrase
        String blockedText = model.getBlockedText();

        // Set the encoded phrase as a request attribute and forward to the result page
        request.setAttribute("blockedText", blockedText);
        request.getRequestDispatcher("result.jsp").forward(request, response);
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Optionally, you can handle GET requests as well if needed
        doPost(request, response);
    }
}
// Index
<%@ page language="jakarta" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<title>Cipher</title>
</head>
<body>
<h1>Square Code Cipher</h1>
<form action="SquareCodeController" method="post">
    <label for="phrase">Enter the phrase to encrypt:</label>
    <input type="text" id="phrase" name="phrase" required>
    <button type="submit">Encrypt</button>
</form>
</body>
</html>

/* ESERCIZIO_03 C# [WPF]
 * MainWindow.xaml.cs
*/
using System.Windows;

namespace NumberToWords;

public partial class MainWindow : Window
{
    private static readonly string[] Units = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    private static readonly string[] Teens = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    private static readonly string[] Tens = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    private static readonly string[] Thousands = { "", "Thousand", "Million", "Billion" };

    public MainWindow()
    {
        InitializeComponent();
    }

    private void OnConvertButtonClick(object sender, RoutedEventArgs e)
    {
        if (long.TryParse(NumberInput.Text, out long number))
        {
            string words = ConvertNumberToWords(number);
            ResultText.Text = words;
        }
        else
        {
            MessageBox.Show("Please enter a valid number.");
        }
    }

    private string ConvertNumberToWords(long number)
    {
        if (number == 0)
            return Units[0];

        if (number < 0)
            return "Minus " + ConvertNumberToWords(-number);

        List<string> parts = new List<string>();
        int thousandGroup = 0;

        while (number > 0)
        {
            int part = (int)(number % 1000);
            if (part > 0)
            {
                string partWords = ConvertPartToWords(part);
                if (thousandGroup > 0)
                    partWords += " " + Thousands[thousandGroup];

                parts.Insert(0, partWords);
            }
            number /= 1000;
            thousandGroup++;
        }

        return string.Join(", ", parts);
    }

    private string ConvertPartToWords(int number)
    {
        List<string> parts = new List<string>();

        if (number >= 100)
        {
            parts.Add(Units[number / 100] + " Hundred");
            number %= 100;
        }

        if (number >= 20)
        {
            parts.Add(Tens[number / 10]);
            number %= 10;
        }
        else if (number >= 10)
        {
            parts.Add(Teens[number - 10]);
            number = 0;
        }

        if (number > 0)
        {
            parts.Add(Units[number]);
        }

        return string.Join(" ", parts);
    }
}
// MainWindow.xaml
<Window x:Class="NumberToWords.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="Number to Words" Height="200" Width="400" Background="#2C2255" WindowStartupLocation="CenterScreen">
    <Grid>
        <StackPanel Margin="20">
            <TextBox x:Name="NumberInput" Height="30" HorizontalAlignment="Stretch" VerticalAlignment="Top" Background="#1C1C1C" Foreground="White" FontSize="16"/>
            <Button Content="Convert" Height="30" Background="#F7941E" Foreground="#2C2255" FontSize="16" Click="OnConvertButtonClick"/>
            <TextBlock x:Name="ResultText" Height="60" Margin="0,10,0,0" Background="#1C1C1C" Foreground="White" FontSize="16" TextWrapping="Wrap"/>
        </StackPanel>
    </Grid>
</Window>