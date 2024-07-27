<%@ page language="java" contentType="text/html; charset=UTF-8" %>
<%@ page import="Model.Calcolatrice" %>
<!DOCTYPE html>
<html>
<head>
    <title>Calcolatrice JSP</title>
</head>
<body>
    <h1>Inserisci un'operazione matematica</h1>
    <form method="post" action="calculate">
        <input type="text" name="input" placeholder="Inserisci l'operazione">
        <input type="submit" value="Calcola">
    </form>

    <%
        String result = (String) request.getAttribute("result");
        if (result != null) {
            out.println("<p>" + result + "</p>");
        }
    %>
</body>
</html>