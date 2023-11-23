
	while(fin >> no >> name >> addr)
	{
		if(no == n)
		{
			fin.seekg(0, ios::beg);
			return addr;
		}
	}
	fin.seekg(0, ios::beg);
	return "NAN";