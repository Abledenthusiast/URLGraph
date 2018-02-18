BUGS: 
	- grab_urls will grab everything that is an <href> - this means local links will most likely fail
		and simpleCurl will output annoying error information about malformed links.
	
ANNOYANCE:
	- source links are not checked for correctness. If the user inputs xavier.blah where blah is not a legal domain, the search will start, but immediately fail.
