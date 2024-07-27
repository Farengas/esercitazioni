// ESERCIZIO_02 C++
#include <iostream>
#include <ctime>

constexpr int MAX_SIZE  { 20 };
constexpr int DIMENSION { 21 };

void generateArray(int array[MAX_SIZE], int count[DIMENSION]);
void findDuplicateValues(int count[DIMENSION]);

int main()
{
    int array[MAX_SIZE];
    int count[DIMENSION] { 0 };
    srand(time(NULL));

    generateArray(array, count);
    findDuplicateValues(count);

    return EXIT_SUCCESS;
}

void generateArray(int array[MAX_SIZE], int count[DIMENSION])
{
    // Generazione e stampa di un array di numeri interi casuali compresi tra 1 e 20.
    for (int i { 0 }; i < MAX_SIZE; i++)
    {
        array[i] = 1 + rand() % 20;
        count[array[i]]++;
    }

    std::cout << "Generated array: { ";
    for (int i { 0 }; i < MAX_SIZE; i++)
        std::cout << array[i] << ' ';
    std::cout << "}\n";
}

void findDuplicateValues(int count[DIMENSION])
{
    // Ricerca e stampa dei valori doppi nell'array.
    bool checker { false };
    std::cout << "\nDuplicate values:\n";
    for (int i { 1 }; i < DIMENSION; i++)
    {
        if (count[i] == 2)
        {
            checker = true;
            printf_s("Number: %2d, count: %2d\n", i, count[i]);
        }
    }
    if (!checker)
        std::cout << "There are no duplicate numbers.\n";
}

// ESERCIZIO_02 Java [JSP]
package it.cefi.views;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.border.EmptyBorder;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class PythagoreanTriplets extends JFrame {
    private JTextField textField;
    private JTextArea textArea;

    Color darkColor = new Color(0x1C1C1C);
    Color purpleColor = new Color(0x2C2255);
    Color orangeColor = new Color(0xF7941E);

    public PythagoreanTriplets() {
        setTitle("Find Pythagorean Triplets");
        setSize(600, 400);
        setVisible(true);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BorderLayout());
        mainPanel.setBackground(darkColor);

        JPanel inputPanel = new JPanel();
        inputPanel.setBorder(new EmptyBorder(10, 10, 10, 10));
        inputPanel.setBackground(purpleColor);

        JLabel label = new JLabel("Enter the value of N:");
        label.setForeground(Color.WHITE);
        inputPanel.add(label);

        textField = new JTextField(10);
        inputPanel.add(textField);

        JButton button = new JButton("Find Triplets");
        button.setBackground(orangeColor);
        button.setForeground(purpleColor);
        button.setFocusPainted(false);
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                findTriplets();
            }
        });
        inputPanel.add(button);
        mainPanel.add(inputPanel, BorderLayout.NORTH);

        textArea = new JTextArea();
        textArea.setEditable(false);
        textArea.setBackground(darkColor);
        textArea.setForeground(Color.WHITE);

        JScrollPane scrollPane = new JScrollPane(textArea);
        mainPanel.add(scrollPane, BorderLayout.CENTER);

        add(mainPanel);
    }

    private void findTriplets() {
        textArea.setText("");
        String inputText = textField.getText().trim(); // Rimuove gli spazi vuoti.
        if (inputText.isEmpty()) {
            textArea.setText("Please enter an integer for N.");
            return;
        }

        int N;
        try {
            N = Integer.parseInt(inputText);
            if (N <= 0) {
                throw new NumberFormatException();
            }
        } catch (NumberFormatException ex) {
            textArea.setText("Please enter a valid positive integer for N.");
            return;
        }

        ArrayList<String> triplets = new ArrayList<>();
        
        // Cerca le triplette pitagoriche che soddisfano a + b + c = N.
        for (int a = 1; a < N; a++) {
            for (int b = a + 1; b < N; b++) {
                double c = Math.sqrt(a * a + b * b);
                if (c == (int) c && a + b + c == N) {
                    triplets.add(a + ", " + b + ", " + (int) c);
                }
            }
        }
        
        // Mostra le triplette trovate.
        if (triplets.isEmpty()) {
            textArea.setText("No Pythagorean triplets found for N = " + N);
        } else {
            StringBuilder result = new StringBuilder();
            result.append("Pythagorean triplets found for N = ").append(N).append(":\n");
            for (String triplet : triplets) {
                result.append(triplet).append("\n");
            }
            textArea.setText(result.toString());
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new PythagoreanTriplets();
            }
        });
    }

}

/* ESERCIZIO_02 C# [ASP.NET MVC]
 * Model
*/
namespace MathematicalParser.Models;

public class MathParserModel
{
    public string? Input { get; set; }
    public string? Result { get; set; }
    public string? Error { get; set; }
}
// Service
using System.Data;
using System.Text.RegularExpressions;

namespace MathematicalParser.Services;

public class MathParserService
{
    private static readonly Regex Pattern = new Regex(@"^[0-9\+\-\*/\s]+$");

    private static double EvaluateExpression(string expression)
    {
        DataTable table = new DataTable();
        DataRow row = table.NewRow();

        table.Columns.Add("expression", typeof(string), expression);
        table.Rows.Add(row);

        return double.Parse((string)row["expression"]);
    }

    public static string ParseAndEvaluate(string input)
    {
        if (string.IsNullOrWhiteSpace(input))
        {
            throw new ArgumentException("Input cannot be empty.");
        }

        if (!Pattern.IsMatch(input))
        {
            throw new ArgumentException("Invalid input. Only numbers and +, -, *, / operators are allowed.");
        }

        try
        {
            var result = EvaluateExpression(input);
            return result.ToString();
        }
        catch (Exception)
        {
            throw new ArgumentException("Invalid mathematical expression.");
        }
    }

}
// Controller
using MathematicalParser.Models;
using MathematicalParser.Services;
using Microsoft.AspNetCore.Mvc;

namespace MathematicalParser.Controllers
{
    public class MathParserController : Controller
    {
        public IActionResult Index()
        {
            return View(new MathParserModel());
        }

        [HttpPost]
        public IActionResult Evaluate(MathParserModel model)
        {
            try
            {
                string? result = MathParserService.ParseAndEvaluate(model.Input);
                model.Result = result;
                model.Error = null;
            }
            catch (Exception ex)
            {
                model.Result = null;
                model.Error = ex.Message;
            }
            return View("Index", model);
        }
    }

}
// Index
@model MathematicalParser.Models.MathParserModel

@{
    ViewData["Title"] = "Mathematical Parser";
}

<div class="container mt-5">
    <h2 style="font-size: 26px;">Enter a mathematical expression:</h2>
    <form asp-action="Evaluate" method="post">
        <div class="d-flex">
            <div class="mb-3 flex-grow-1 me-3">
                <input type="text" id="txtInput" asp-for="Input" class="form-control" placeholder="Enter a mathematical expression" />
            </div>
            <button type="submit" class="custom-button btn-primary">Submit</button>
        </div>
    </form>

    @if (Model.Result != null)
    {
        <div class="alert alert-success mt-3" role="alert">
            <span>Result: @Model.Result</span>
        </div>
    }

    @if (Model.Error != null)
    {
        <div class="alert alert-danger mt-3" role="alert">
            <span>Error: @Model.Error</span>
        </div>
    }
</div>
// Layout
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>@ViewData["Title"] - MathematicalParser</title>
    <link rel="stylesheet" href="~/lib/bootstrap/dist/css/bootstrap.min.css" />
    <link rel="stylesheet" href="~/css/site.css" asp-append-version="true" />
    <link rel="stylesheet" href="~/MathematicalParser.styles.css" asp-append-version="true" />
</head>
<body>
    <div class="container">
        <main role="main">
            @RenderBody()
        </main>
    </div>
    <script src="~/lib/jquery/dist/jquery.min.js"></script>
    <script src="~/lib/bootstrap/dist/js/bootstrap.bundle.min.js"></script>
    <script src="~/js/site.js" asp-append-version="true"></script>
    @await RenderSectionAsync("Scripts", required: false)
</body>
</html>
// Css
span {
    font-size: 18px;
}

.custom-button {
    width: auto;
    height: 40px;
}