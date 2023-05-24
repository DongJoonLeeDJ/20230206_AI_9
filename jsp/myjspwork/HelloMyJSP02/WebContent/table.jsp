<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

	<table border=2>
		<thead>
			<%String[] arrs = 
			{"X","2","3","4","5","6","7","8","9"}; 
			for(String item : arrs) {
				%>
			<th><%out.println(item);%>
			</th>
			<%} %>
		</thead>
		<tbody>
			<%for(int i = 1; i<=9; i++) {%>
			<tr> <%for(int j = 1; j<=9; j++) { %>
					<td><% out.println(i*j);%></td>
				<%} %>
			<%} %>
		</tbody>
	</table>


	<table border=1>
		<thead>
			<th>X</th>
			<th>2</th>
			<th>3</th>
			<th>4</th>
			<th>5</th>
			<th>6</th>
			<th>7</th>
			<th>8</th>
			<th>9</th>
		</thead>
		<tbody>
			<tr>
				<td>1</td>
				<td>2</td>
				<td>3</td>
				<td>4</td>
				<td>5</td>
				<td>6</td>
				<td>7</td>
				<td>8</td>
				<td>9</td>
			</tr>
			<tr>
				<td>2</td>
				<td>4</td>
				<td>6</td>
				<td>8</td>
				<td>10</td>
				<td>12</td>
				<td>14</td>
				<td>16</td>
				<td>18</td>
			</tr>
			<tr>
				<td>3</td>
				<td>6</td>
				<td>9</td>
				<td>12</td>
				<td>15</td>
				<td>18</td>
				<td>21</td>
				<td>24</td>
				<td>27</td>
				</tr>
			<tr>
				<td>4</td>
				<td>8</td>
				<td>12</td>
				<td>16</td>
				<td>20</td>
				<td>24</td>
				<td>28</td>
				<td>32</td>
				<td>36</td>
				</tr>
			<tr>
				<td>5</td>
				<td>10</td>
				<td>15</td>
				<td>20</td>
				<td>25</td>
				<td>30</td>
				<td>35</td>
				<td>40</td>
				<td>45</td>
				</tr>
			<tr>
				<td>6</td>
				<td>12</td>
				<td>18</td>
				<td>24</td>
				<td>30</td>
				<td>36</td>
				<td>42</td>
				<td>48</td>
				<td>54</td>
				</tr>
			<tr>
				<td>7</td>
				<td>14</td>
				<td>21</td>
				<td>28</td>
				<td>35</td>
				<td>42</td>
				<td>49</td>
				<td>56</td>
				<td>63</td>
				</tr>
			<tr>
				<td>8</td>
				<td>16</td>
				<td>24</td>
				<td>32</td>
				<td>40</td>
				<td>48</td>
				<td>56</td>
				<td>64</td>
				<td>72</td>
				</tr>
			<tr>
				<td>9</td>
				<td>18</td>
				<td>27</td>
				<td>36</td>
				<td>45</td>
				<td>54</td>
				<td>63</td>
				<td>72</td>
				<td>81</td>
				</tr>
		</tbody>
	</table>
</body>
</html>