#!/usr/bin/perl

my $input;
my $file = '.4perl';
open($input, '<',$file);

my $defLostBytes;
my $indLostBytes;
my $posLostBytes;
my $errors;

while (my $line = <$input>)
{
    if (index($line,'definitely lost') != -1)
    {
        if ($line =~ m{: ((?:\d+,)*\d+) bytes in ((?:\d+,)*\d+) blocks})
        {
            $defLostBytes = $1;
            #print "Definitely lost bytes: $defLostBytes\n";
        }
    }
    elsif (index($line,'indirectly lost') != -1)
    {
        if ($line =~ m{: ((?:\d+,)*\d+) bytes in ((?:\d+,)*\d+) blocks})
        {
            $indLostBytes = $1;
            #print "Indirectly lost bytes: $indLostBytes \n";
        }
    }
    elsif (index($line,'possibly lost') != -1)
    {
        if ($line =~ m{: ((?:\d+,)*\d+) bytes in ((?:\d+,)*\d+) blocks})
        {
            $posLostBytes = $1;
            #print "Possibly lost bytes: $posLostBytes \n";
        }
    }
    elsif (index($line,'ERROR') != -1)
    {
        if ($line =~ m{: ((?:\d+,)*\d+) errors from ((?:\d+,)*\d+) contexts})
        {
            $errors = $1;
            #print "Errors: $errors \n";
        }
    }
}

my $memCheckPassed = "false";

$memCheckPassed = "true" unless ($errors or $defLostBytes);

close($input);

printf("%d %d %s",$defLostBytes, $errors, $memCheckPassed);

