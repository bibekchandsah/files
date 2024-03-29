import java.sql.*;
public class QueryApp2
{
	public static void main(String a[])
	{
		ResultSet result;
		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection con = DriverManager.getConnection("jdbc:odbc:mahendra2","sa","");
 			Statement stat = con.createStatement();

			result = stat.executeQuery("Select * from externalcandidate where vFirstName = 'Angela'");

			while(result.next())
			{
				System.out.println(result.getString(1)+"   "+result.getString(2)+"   "+result.getString(3));
			}
		}
		catch(Exception e)
		{
			System.out.println("Could not execute the query" +e);
		}
	}
}