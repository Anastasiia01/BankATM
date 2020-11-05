class BusinessAccount:public Account {
	//test
	private:
		long EIN; //Employer Identification Number
		String CompanyName;

	protected:
		void setEIN(int s) { EIN = s; }
		void setCompanyName(String nam) { CompanyName = nam};
		

	public:
		long getEIN() { return EIN; }
		String getCompanyName() { return CompanyName; }
};
