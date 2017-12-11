function mbitSettings ()
    mbit.settitle("Test Cartridge");
    mbit.setauthor("by JDTAY");
    mbit.setline(1,3,"press z, c, and arrows for input");
end

function mbitLoop ( a )
    if a == 0 then mbit.setline(1,4,"no input detected") else mbit.setline(1,4," ") end
    if a&1 == 1 then mbit.setline(1,5,"c") else mbit.setline(1,5," ") end
    if a&2 == 2 then mbit.setline(1,6,"z") else mbit.setline(1,6," ") end
    if a&4 == 4 then mbit.setline(1,7,"^") else mbit.setline(1,7," ") end
    if a&8 == 8 then mbit.setline(1,8,"v") else mbit.setline(1,8," ") end
    if a&16 == 16 then mbit.setline(1,9,"<") else mbit.setline(1,9," ") end
    if a&32 == 32 then mbit.setline(1,10,">") else mbit.setline(1,10," ") end
end
