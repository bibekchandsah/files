import java.sql.*;
public class QueryApp6
{
	public static void main(String a[])
	{
		ResultSet result;
		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection con = DriverManager.getConnection("jdbc:odbc:mahendra2","sa","");
 			PreparedStatement stat = con.prepareStatement("Select * from externalcandidate where vFirstName =?");
			stat.setString(1,a[0]);
			//stat.setString(2,a[1]);
			result = stat.executeQuery();

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