#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#ifndef GRAB_URLS_H
#define GRAB_URLS_H

/** 
 * @author originally developed by the writer/s of Accelerated C++ 
 * @author/implemented by Aaron Pitman 
 * @version 2015.11.04
 */

using namespace std;

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";

	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

class grab_urls
{

public:

grab_urls(){}

vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	//view the entire input
	while (b != e)
	{
		b = url_beg(b, e);
		//found it
		if(b != e)
		{
			// get rest of url
			iter after = url_end(b, e);

			//store url in vector
			ret.push_back(string(b, after));

			// advance b and check for more urls
			b = after;

		}
	}
	return ret;
}


string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
	
	return find_if(b, e, not_url_char);
}

string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "href=\"";

	typedef string::const_iterator iter;

	// i marks where the seperator was found
	iter i = b;
	while((i = search(i, e, sep.begin(), sep.end())) != e)
	{
		// make sure the seperator isn't at the beginning or end of the line
		if(i !=b && i + sep.size() != e)
		{
			// beg is the beginning of the protocol-name
			iter beg = i+6;
			if(beg != i && !not_url_char(i[sep.size()]))
			{
				return beg;
			}
			// seperator that was found wasn't part of a URL
			i += sep.size();
		}
	}
	return e;
}

};
#endif
