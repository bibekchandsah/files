import java.sql.*;

public class QueryApp1
{
	public static void main(String a[])
	{
		ResultSet R1;
		ResultSet R2;
		ResultSet R3;
		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection con = DriverManager.getConnection("jdbc:odbc:mahendra2");
			Statement stat1 = con.createStatement();
			R1 = stat1.executeQuery("Select * from college");
			System.out.println("Data of the college table \n");

			while(R1.next())
			{
				System.out.println(R1.getString(1)+"   "+R1.getString(2)+"   "+R1.getString(3));;
			}
			Statement stat2 = con.createStatement();
			R2 = stat2.executeQuery("Select * from externalcandidate");
			System.out.println("\n Data of the externalcandidate Table \n");

			while(R2.next())
			{
				System.out.println(R2.getString(1)+"   "+R2.getString(2)+"   "+R2.getString(3));
			}
			Statement stat3 = con.createStatement();
			R3 = stat3.executeQuery("Select vFirstName,cName from ExternalCandidate e JOIN RecruitmentAgencies r on e.cAgencyCode=r.cAgencyCode");
			System.out.println("\n Data of the Two Tables Using Join Table \n");

			while(R3.next())
			{
				System.out.println(R3.getString(1)+"   "+R3.getString(2));
			}
		}
		catch(Exception e)
		{
			System.out.println("Could not execute the query" +e);
		}
	}
}