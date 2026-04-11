#include "../../../Utils/csapp.h"

#define PROCESS_COUNT 4
#define TOTAL_OUTPUT_LENGTH 6
#define MAX_RESULTS 180

static const char *process_outputs[PROCESS_COUNT] = {"1", "0", "12", "02"};
static char results[MAX_RESULTS][TOTAL_OUTPUT_LENGTH + 1];
static int result_count = 0;

static int compare_outputs(const void *left, const void *right)
{
    return strcmp((const char *)left, (const char *)right);
}

static int output_exists(const char *candidate)
{
    int i;

    for (i = 0; i < result_count; i++) {
        if (strcmp(results[i], candidate) == 0)
            return 1;
    }

    return 0;
}

static void save_output(const char *candidate)
{
    if (output_exists(candidate))
        return;

    strcpy(results[result_count], candidate);
    result_count++;
}

static void enumerate_outputs(int positions[PROCESS_COUNT], char current[], int next)
{
    int i;

    if (next == TOTAL_OUTPUT_LENGTH) {
        current[next] = '\0';
        save_output(current);
        return;
    }

    for (i = 0; i < PROCESS_COUNT; i++) {
        if (process_outputs[i][positions[i]] == '\0')
            continue;

        current[next] = process_outputs[i][positions[i]];
        positions[i]++;
        enumerate_outputs(positions, current, next + 1);
        positions[i]--;
    }
}

int main(void)
{
    int positions[PROCESS_COUNT] = {0};
    char current[TOTAL_OUTPUT_LENGTH + 1];
    int i;

    /* The original program creates processes that emit: 1, 0, 12, and 02. */
    enumerate_outputs(positions, current, 0);
    qsort(results, result_count, sizeof(results[0]), compare_outputs);

    printf("All possible outputs (%d):\n", result_count);
    for (i = 0; i < result_count; i++)
        printf("%s\n", results[i]);

    return 0;
}
