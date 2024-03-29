// For Insert
import java.sql.*;
public class QueryApp7
{
	public static void main(String a[])
	{
		ResultSet result;
		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection con = DriverManager.getConnection("jdbc:odbc:pu","sa","");
 			Statement stat = con.createStatement();

			stat.executeUpdate("insert into student values(1,'Amit Dash','12/09/2005')");
			System.out.println("Data Inserted In the Table");

			//while(result.next())
			//{
				//System.out.println(result.getString(1)+"   "+result.getString(2)+"   "+result.getString(3));
			//}
		}
		catch(Exception e)
		{
			System.out.println("Could not execute the query" +e);
		}
	}
}