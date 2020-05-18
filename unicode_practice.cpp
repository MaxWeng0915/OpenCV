	cv::Mat readcvunicode(std::wstring filename)
	{
		FILE* fp = _wfopen(filename.c_str(), L"rb");
		if (!fp)
		{
			return Mat::zeros(1, 1, CV_8U);
		}
		fseek(fp, 0, SEEK_END);
		long sz = ftell(fp);
		char* buf = new char[sz];
		fseek(fp, 0, SEEK_SET);
		long n = fread(buf, 1, sz, fp);
		_InputArray arr(buf, sz);
		Mat img = imdecode(arr, IMREAD_UNCHANGED);
		delete[] buf;
		fclose(fp);
		return img;
	}
	
	int writecvunicode(std::wstring filename, cv::Mat src, int typ)
	{
		std::vector<uchar> data_encode;
		if(typ == 0)
			imencode(".bmp", src, data_encode);
		else 
			imencode(".jpeg", src, data_encode);

		FILE* fp = _wfopen(filename.c_str(), L"wb");
		if (!fp)
		{
			fclose(fp);
			return 0;
		}

		uchar* ImgBuffer = (uchar*)malloc(data_encode.size() * sizeof(uchar));
		for (int i = 0; i < data_encode.size(); i++) {
			ImgBuffer[i] = data_encode[i];
		}
		fwrite(ImgBuffer, data_encode.size(), 1, fp);
		fclose(fp);
		free(ImgBuffer);
		return 1;

	}