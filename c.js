function countUserLogins(logs) {
    // Parse logs
    const parsedLogs = logs.map(entry => entry.replace(/\s+$/g, '').split(' '));

    // Filter invalid entries
    const logsFiltered = parsedLogs.filter(entry => {
        const [username, time, date] = entry;
        const timeRegex = /^([01]\d|2[0-3]):[0-5]\d:[0-5]\d$/;
        const dateRegex = /^(19|20)\d\d-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$/;
        return timeRegex.test(time) && dateRegex.test(date);
    });

    // Sort logs lexicographically based on user_id and login_date
    logsFiltered.sort((a, b) => {
        const [userA, dateA] = [a[0], a[2]];
        const [userB, dateB] = [b[0], b[2]];

        if (userA !== userB) {
            return userA.localeCompare(userB);
        } else {
            return dateA.localeCompare(dateB);
        }
    });

    const loginCounts = {};

    // Update login counts in the dictionary
    for (const entry of logsFiltered) {
        const [username, _, date] = entry;
        const key = `${username} ${date}`;
        loginCounts[key] = (loginCounts[key] || 0) + 1;
    }

    // Create the final result array as strings
    const result =