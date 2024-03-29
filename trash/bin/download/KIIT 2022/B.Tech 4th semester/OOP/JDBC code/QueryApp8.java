// For Update
import java.sql.*;
public class QueryApp7
{
	public static void main(String a[])
	{
		ResultSet result;
		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection con = DriverManager.getConnection("jdbc:odbc:mahendra2","sa","");
 			Statement stat = con.createStatement();

			stat.executeUpdate("Update Externalcandidate Set vFirstName='Angela' Where cCandidateCode='000001'");
			System.out.println("Data Updated In the Table");

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