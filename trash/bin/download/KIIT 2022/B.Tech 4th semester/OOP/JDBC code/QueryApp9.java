// For Delete
import java.sql.*;
public class QueryApp9
{
	public static void main(String a[])
	{
		ResultSet result;
		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection con = DriverManager.getConnection("jdbc:odbc:mahendra2","sa","");
 			Statement stat = con.createStatement();

			stat.executeUpdate("Delete Newsad Where cNewsAdNo='0016'");
			System.out.println("Data Deleted In the Table");

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