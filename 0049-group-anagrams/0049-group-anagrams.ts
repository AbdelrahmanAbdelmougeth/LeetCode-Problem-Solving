function groupAnagrams(strs: string[]): string[][] {
    const strStrVector = new Map<string, string[]>();
    for(const str of strs){
        const sortedString = str.split('').sort().join('');
        if(!strStrVector.has(sortedString))
            strStrVector.set(sortedString, [])
        strStrVector.get(sortedString).push(str);   
    }
    
    /*
    // the traditional way 
    const ans: string[][] = [];
    for (const x of strStrVector.values()) {
        ans.push(x);
    }

    return ans;
    */
    
    return Array.from(strStrVector.values());
};