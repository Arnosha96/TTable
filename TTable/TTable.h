#pragma once
#include<string>

using namespace std;
class TRecord
{
public:
	string Key;
	int Data;
	TRecord()
	{
		int Key = 0;
	}

	TRecord(string _Key, int _Data)
	{
		Key = _Key;
		Data = _Data;
	}

	TRecord operator= (const TRecord&Rec)
	{
		Key = Rec.Key;
		Data = Rec.Data;
		return *this;
	}
};
	class TTable
	{
	private:
		int Size;
		TRecord *List;
		int Count;
	public:
		TTable(int _Size = 100)
		{
			Size = _Size;
			List = new TRecord[Size];
			Count = 0;
		}
		~TTable()
		{
			delete[]List;
		}

		/*TRecord &operator[](int pos)
		{
			if ((pos >= 0) && (pos < Count))
				return List[pos];
		}*/

	    int operator[](string k)
		{
			for (int i(0); i < Count; i++)
			{
				if (List[i].Key == k) return List[i].Data;

			}
			return -1;
		}
		int AddRecord(TRecord &Rec)
		{
			if (Count < Size)
			{
				for (int i(0); i < Count; i++)
				{
					if (Rec.Key == List[i].Key)
					if (Rec.Data == List[i].Data)
						return 1;
					else return 0;
				}

				List[Count] = Rec;
				Count++;
				return 1;
			}
			else return 0;
		}
		bool DelRecord(string RecKey)
		{
			int pos;
			pos = SeachRecord(RecKey);
			if (pos == -1) return false;
			else
			{
				for (int i = pos; i < Count - 1; i++)
					List[i] = List[i + 1];
				Count--;
				return true;
			}
		}
		int SeachRecord(string RecKey)
		{
			for (int i(0); i < Count; i++)
			{
				if (List[i].Key == RecKey) return i;
			}

			return -1;
		}

		void Print()
		{
			for (int i(0); i < Count; i++)
			{
				cout << List[i].Key << " " << List[i].Data << endl;
			}
		}

	
	};